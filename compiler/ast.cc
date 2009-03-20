#include "ast.h"
#include <stdarg.h>

namespace ast {

int id=0;

/* id_t:: */
id_t::id_t(const char *name_)  : name(name_)
{
}

ast_t *fn_call(const char *name, ...)
{
	ast_t *ret;
	va_list ap;
	va_start(ap,name);
	ret = new id_t(name);
	for(;;) {
		ast_t *arg=va_arg(ap,ast_t*);
		if (!arg)
			break;
		ret=new fncall_t(ret,arg);
	}
	va_end(ap);

	return ret;
}

ast_t *fn_def(std::string name, vars_t *args, block_t *body)
{
	if (args->size()<=1) {
		return new fn_t(name,args,body);
	}
	vars_t::const_iterator start = args->begin();
	++start;

	vars_t *subargs = new vars_t(start,args->end());
	vars_t *topargs = new vars_t(args->begin(),start);
	
	block_t *mybody = new block_t();
	mybody->push_sentence(
			fn_def(std::string("curried_")+name,
			subargs,
			body));
	return new fn_t(name,topargs,mybody);
}

}
