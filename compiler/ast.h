#include <string>
#include <deque>
#include <iostream>
#include <set>
#include <sstream>
#include <cassert>
#include <boost/lexical_cast.hpp>

namespace ast {

extern int id;

typedef std::set<std::string> vars_t;

struct scope_t {
	typedef std::set<std::string> localvars_t;
	localvars_t localvars;
	scope_t *parent;
	std::string name;

	scope_t(std::string name_, scope_t *parent_)
		: parent(parent_), name(name_)
		{}

	bool varExists(const std::string &var) const {
		return localvars.find(var) != localvars.end() 
			|| (parent && parent->varExists(var));
	}

	void newVar(const std::string &var) {
		localvars.insert(var);
	}

	void reference(const std::string &var) {
		if (!varExists(var)) {
			newVar(var);
		}
	}

	std::string emitC(const std::string &var) {
		if (localvars.find(var) != localvars.end()) {
			return std::string("var_") + var;
		}

		return std::string("parent->") + parent->emitC(var);
	}

	void emitCdecl() {
		for(localvars_t::const_iterator it=localvars.begin();
				it!=localvars.end();
				++it) {
			std::cout << " nile_t *var_" << *it << ";\n";
		}
	}

};

class fn_t;

class ast_t {
	protected:
		scope_t *scope;
	public:
		ast_t() : scope(0) {};
		/* Scope check */
		virtual void check(scope_t *symtab) {scope=symtab;};
		/* Forward Declationations */
		virtual void emitCdecl() { };
		/* Global definitions */
		virtual void emitCglobal() { };
		/* Statement itself */
		virtual void emitC() { std::cout << "NULL/* abstract emitC */";};
		virtual std::string getName(void) const {
			return std::string("abstract");
		}
		virtual ~ast_t() {};
};

class id_t : public ast_t {
	public:
		std::string name;
		id_t(const char *name_);

		void check(scope_t *symtab) 
		{
			scope=symtab;
			assert(symtab);
			symtab->reference(name);
		}

		std::string getName(void) const {
			return name;
		}

		void emitC() 
		{ 
			assert(scope);
			std::cout << scope->emitC(name);
		};

};

class num_t : public ast_t {
	public:
		int value;
		num_t(int value_) : value(value_)
		{ }
		void emitC() 
		{
			std::cout << "new nilep_number(" << value << ")";
		}
};

class string_t : public ast_t {
	public:
		std::string value;
		string_t(const char* value_)
			: value(value_)
		{
		};
		void emitC() 
		{
			std::cout << "new nilep_string(L\"" << value << "\")";
		}
};

class fncall_t : public ast_t {
	public:
		ast_t *func;
		ast_t *arg;
		fncall_t (ast_t *func_, ast_t *arg_)
			: func(func_), arg(arg_)
			{ assert(arg); }

		std::string getName(void) const 
		{
			return std::string("call ")+func->getName();
		}

		void check(scope_t *symtab)
		{
			assert(symtab);
			scope=symtab;
			arg->check(symtab);
			func->check(symtab);
		}
		void emitCdecl()
		{
			arg->emitCdecl();
			func->emitCdecl();
		}
		void emitC() 
		{
			assert(scope);
			func->emitC();
			std::cout << "->call(";
			arg->emitC();
			std::cout << ")";
		}
		void emitCglobal()
		{
			assert(scope);
			func->emitCglobal();
			arg->emitCglobal();
		}
};

class assign_t : public ast_t {
		ast_t *dest;
		ast_t *expr;
	public:
		assign_t (ast_t *dest_, ast_t *expr_)
			: dest(dest_), expr(expr_)
			{ assert(expr); }
		void check(scope_t *scope_)
		{
			dest->check(scope_);
			expr->check(scope_);
			scope=scope;
		}
		void emitC()
		{
			dest->emitC();
			std::cout << "=";
			expr->emitC();
		}
		void emitCglobal()
		{
			dest->emitCglobal();
			expr->emitCglobal();
		}
		void emitCdecl()
		{
			dest->emitCdecl();
			expr->emitCdecl();
		}
		std::string getName(void) const {
			return "assignment";
		}
};

class block_t : public ast_t {
		typedef std::deque<ast_t *> container_t;
		container_t sentences;
		scope_t *myscope;
		int myid;
	public:
		block_t() {
			myid=id++;
		}
		void push_sentence(ast_t *sent)
		{
			sentences.push_front(sent);
		}
		std::string getName(void) const
		{
			return std::string("closure_")+boost::lexical_cast<std::string>(myid);
		}

		void check(scope_t *scope_)
		{
			scope=scope_;
			myscope = new scope_t(getName(),scope);
			for(container_t::iterator i=sentences.begin();
					i!=sentences.end();
					++i) {
				(*i)->check(myscope);
			}

		}

		void emitCdecl()
		{
			assert(scope);
			for(container_t::iterator i=sentences.begin();
					i!=sentences.end();
					++i) {
				(*i)->emitCdecl();
			}
			std::cout << "struct " << getName() << " : public nile_t {\n";
			std::cout << " class " << scope->name << " *parent;\n";
			myscope->emitCdecl();
			std::cout << " " << getName() << "(" << scope->name << " *parent_);\n"
				  << " nile_t *call();\n";
			std::cout << "};\n\n";

		}

		void emitCglobal()
		{
			for(container_t::iterator i=sentences.begin();
					i!=sentences.end();
					++i) {
				(*i)->emitCglobal();
			}
			std::cout << getName() << "::" <<getName() 
				<< "(class " << scope->name << " *parent_) : parent(parent_) {}\n";
			std::cout << "nile_t *" <<getName() << "::call(void) {\n";
			std::cout << "  nile_t *ret;\n";
			for(container_t::iterator i=sentences.begin();
					i!=sentences.end();
					++i) {
				std::cout << "  ret=";
				(*i)->emitC();
				std::cout << ";\n";
			}
			std::cout << "  return ret;\n";
			std::cout << "}\n\n";
		}
		void emitC()
		{
			assert(scope);
			std::cout << "(new " << getName() << "(this))";
		}
};


class fn_t : public ast_t {
	private:
		std::string name;
		vars_t *vars;
		block_t *body;
		scope_t *myscope;
		int myid;
	public:
		fn_t(std::string name_, vars_t *args_, block_t *body_)
			: name(name_), vars(args_), body(body_), myscope(0),
			myid(id++)
		{ }

		std::string getName(void) const
		{
			return std::string("nile_")+name;
		}
		void check(scope_t *scope_) {
			scope=scope_;
			assert(!myscope);
			myscope = new scope_t(getName(),scope);

			if (vars->begin() != vars->end())
				myscope->newVar(*vars->begin());

			body->check(myscope);
		}
		void emitCdecl()
		{
			std::cout << "struct " << getName() << " : public nile_t {\n";
			std::cout << " class " << scope->name << " *parent;\n";
			myscope->emitCdecl();
			std::cout << " " << getName() << "(" << scope->name << " *parent_);\n";
			if (vars->begin() != vars->end())
				std::cout << " nile_t *call(nile_t *);\n ";
			else
				std::cout << " nile_t *call();\n ";
			std::cout << "};\n\n";
			body->emitCdecl();

		}
		void emitCglobal()
		{
			body->emitCglobal();

			std::cout << getName() << "::" << getName() << "(" << scope->name << " *parent_) : parent(parent_) {}\n";
			std::cout << "\n";
			if (vars->begin() != vars->end()) {
				std::cout << "nile_t *" <<getName()<< "::call(nile_t *" << *vars->begin() << "_) {\n";
				for(vars_t::const_iterator it=vars->begin();
					it!=vars->end();
					++it) {
					std::cout << " var_" << *it << "=" << *it << "_;\n";
				}
			} else
				std::cout << "nile_t *" <<getName()<< "::call() {\n";
			std::cout << " return ";
			body->emitC();
			std::cout << "->call();\n}\n";

		}

		void emitC()
		{
			std::cout << "(new " << getName() << "(this))";
		}
};

ast_t *fn_call(const char *name, ...);
ast_t *fn_def(std::string name, vars_t *args, block_t *body);

}
