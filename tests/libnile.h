#include <string>
#include <boost/lexical_cast.hpp>
#include <cassert>

struct nile_t {
	virtual nile_t *call() { return this; };
	virtual nile_t *call(nile_t *x) { abort(); };
	virtual int cmp(const nile_t *rhs) const { 
		if (this<rhs) {
			return -1;
		}
		else if (this == rhs) {
			return 0;
		}
		return +1;
	};
	virtual std::wstring toString() { return std::wstring(L"Object"); };
	virtual ~nile_t() { };
};

struct nile_print_t : public nile_t {
	nile_t *call(nile_t *x) {
		if (!x) {
			fprintf(stderr,"Attempt to print undefined variable\n");
			abort();
		}
		wprintf(L"%s",x->toString().c_str());
		return this;
	}
};

#include "libnile_string.h"

struct nilep_number : public nile_t {
	int value;
	nilep_number(int val) : value(val) {};
	std::wstring toString() { return boost::lexical_cast<std::wstring>(value); };
	int cmp(const nile_t *rhs) const {
		if (dynamic_cast<const nilep_number*>(rhs)==0)
			return nile_t::cmp(rhs);
		return value-dynamic_cast<const nilep_number*>(rhs)->value;
	}
};

nile_t *nile_nil(new nile_t);
nile_t *nile_zero(new nilep_number(0));
nile_t *nile_one(new nilep_number(1));


#define binop(name,op) \
	struct nilep_curried ## name : public nile_t { 			\
		nile_t *lhs;						\
	public:								\
		nilep_curried ## name(nile_t *value_) : lhs(value_) {}\
		nile_t *call(nile_t *rhs) {				\
			assert(lhs);					\
			assert(rhs);					\
			assert(dynamic_cast<nilep_number*>(rhs));	\
			nile_t *ret=new nilep_number(dynamic_cast<nilep_number&>(*lhs).value op dynamic_cast<nilep_number&>(*rhs).value);			\
			return ret;					\
		} 							\
}; 									\
struct nilep_##name : public nile_t {					\
	nile_t *call(nile_t *lhs) {					\
		assert(dynamic_cast<nilep_number*>(lhs));		\
		return new nilep_curried ## name(lhs);			\
	}								\
};									\

binop(add,+)
binop(sub,-)
binop(mul,*)
binop(div,/)
binop(mod,%)

#undef binop

#define relop(name,op)							\
struct nile_curried ## name : public nile_t {				\
	nile_t *lhs;							\
	nile_curried##name(nile_t *lhs_) : lhs(lhs_) {}			\
	nile_t *call(nile_t *rhs) {					\
		if (!lhs) { fprintf(stderr,"Comparison of undefined variable\n"); abort(); } \
		if (!rhs) { fprintf(stderr,"Comparison of undefined variable\n"); abort(); } \
		if ((1 op 1 && lhs == rhs)				\
		  || lhs->cmp(rhs) op 0) {				\
			return nile_one;				\
		}							\
		else {							\
			/* Should return a nilep_false */		\
			return nile_zero;				\
		}							\
	}								\
};									\
struct nile_## name : public nile_t {					\
	nile_t *call(nile_t *lhs) {					\
		return new nile_curried ## name(lhs);			\
	}								\
};

relop(lessthan,<)
relop(lessthaneq,<=)
relop(greaterthan,>)
relop(greaterthaneq,>=)
relop(equal,==)
relop(noteq,!=)

#undef relop

struct nile_if_true_else_t : public nile_t {
	nile_t *ret;
	nile_if_true_else_t(nile_t *ret_) : ret(ret_) {}
	nile_t *call(nile_t *ifFalse) {
		/* Ignore the else condition */
		return ret;
	}
};

struct nile_if_true_t : public nile_t {
	nile_t *call(nile_t *ifTrue) {
		ifTrue = ifTrue->call(); /* Evaluate the true condition */

		return new nile_if_true_else_t(ifTrue);
	}
};

struct nile_if_false_else_t : public nile_t {
	nile_t *call(nile_t *ifFalse) {
		nile_t *x=ifFalse->call();
		return x;
	}
};

struct nile_if_false_t : public nile_t {
	nile_t *call(nile_t *ifTrue) {
		/* Ignore the true condition */
		return new nile_if_false_else_t();
	}
};

struct nile_if_t : public nile_t {
	nile_t *call(nile_t *cond) {
		cond = cond->call(); /* Evaulate condition */
		if (cond->cmp(nile_zero)!=0) {
			return new nile_if_true_t();
		}
		else {
			return new nile_if_false_t();
		}
	}
};

struct nile_break_exception_t : public std::exception {
};

struct nile_break_t : public nile_t {
	nile_t *call(void) {
		throw nile_break_exception_t();
	}
};

struct nile_loop_t : public nile_t {
	nile_t *call(nile_t *block) {
		try {
			for(;;) {
				block->call();
			}
		}
		catch(nile_break_exception_t &ex) {
		}
		return nile_nil;
	}
};

struct nile_curried_apply_t : public nile_t {
	nile_t *callable;
	nile_curried_apply_t(nile_t *callable_) : callable(callable_) {}
	nile_t *call(nile_t *args) {
		return callable->call();
	}
};

struct nile_apply_t : public nile_t {
	nile_t *call(nile_t *callable) {
		return new nile_curried_apply_t(callable);
	}
};

struct nile_conscell_t : public nile_t {
	nile_t *head;
	nile_t *tail;
	nile_conscell_t(nile_t *head_, nile_t *tail_) 
		: head(head_), tail(tail_) {}
	int cmp(const nile_t *rhs) const {
		int ret;
		if (dynamic_cast<const nile_conscell_t*>(rhs)==0)
			return nile_t::cmp(rhs);
		ret=head->cmp(dynamic_cast<const nile_conscell_t*>(rhs)->head);
		if (ret==0) {
			ret=tail->cmp(dynamic_cast<const nile_conscell_t*>(rhs)
				->tail);
		}
		return ret;
	}
};

struct nile_cons_callable_t : public nile_t {
	nile_t *head;
	nile_cons_callable_t(nile_t *head_) : head(head_) {}
	nile_t *call(nile_t *tail) { 
		return new nile_conscell_t(head,tail);
	}
};

struct nile_cons_t : public nile_t {
	nile_t *call(nile_t *head) {
		return new nile_cons_callable_t(head);
	}
};

struct nile_head_t : public nile_t {
	nile_t *call(nile_t *list) {
		return dynamic_cast<const nile_conscell_t&>(*list).head;
	}
};

struct nile_tail_t : public nile_t {
	nile_t *call(nile_t *list) {
		return dynamic_cast<const nile_conscell_t&>(*list).tail;
	}
};

class global {
	public:
	nile_t *var_print;
	nile_t *var_nil;
	/* flow control */
	nile_t *var_if;
	nile_t *var_loop;
	nile_t *var_break;
	nile_t *var_apply;
	/* relops */
	nile_t *var_lessthan;
	nile_t *var_lessthaneq;
	nile_t *var_greaterthan;
	nile_t *var_greaterthaneq;
	nile_t *var_equal;
	nile_t *var_noteq;
	/* binops */
	nile_t *var_add;
	nile_t *var_sub;
	nile_t *var_div;
	nile_t *var_mul;
	nile_t *var_mod;
	/* list ops */
	nile_t *var_cons;
	nile_t *var_head;
	nile_t *var_tail;

	global() :
		var_print(new nile_print_t),
		var_nil(nile_nil),
		/* flow control */
		var_if(new nile_if_t),
		var_loop(new nile_loop_t),
		var_break(new nile_break_t),
		var_apply(new nile_apply_t),
		/* relops */
		var_lessthan(new nile_lessthan),
		var_lessthaneq(new nile_lessthaneq),
		var_greaterthan(new nile_greaterthan),
		var_greaterthaneq(new nile_greaterthaneq),
		var_equal(new nile_equal),
		var_noteq(new nile_noteq),
		/* binops */
		var_add(new nilep_add()),
		var_sub(new nilep_sub()),
		var_div(new nilep_div()),
		var_mul(new nilep_mul()),
		var_mod(new nilep_mod()),
		/* list ops */
		var_cons(new nile_cons_t()),
		var_head(new nile_head_t()),
		var_tail(new nile_tail_t())
	{}

		
};


