#include "ast.h"

void emitC(id_t &id)
{
	std::cout << "id_" << id.name;
}

void emitC(num_t &node)
{
	std::cout << "new nilep_number(" << node.value << ")";
}

void emitC(string_t &node)
{
	std::cout << "new nilep_string(\"" << node.value << "\")";
}

void emitC(fncall_t &node,vars_t *symtab)
{
	emitC(*node.func,symtab);
	std::cout << "->call(";
	emitC(*node.arg,symtab);
	std::cout << ")";
}

void emitCglobal(fncall_t &node, vars_t *symtab)
{
	emitCglobal(*node.func,symtab);
	emitCglobal(*node.arg,symtab);
}

void emitC(assign_t &node, vars_t *symtab)
{
	emitC(*node.dest,symtab);
	std::cout << "=";
	emitC(*node.expr,symtab);
}

void emitCglobal(assign_t &node, vars_t *symtab)
{
	emitCglobal(*node.dest,symtab);
	emitCglobal(*node.expr,symtab);
}

void emitCglobal(fn_t &node, vars_t *symtab)
{
	vars_t newsymtab = *symtab;
	newsymtab.insert(vars->begin(),vars->end());
	emitCglobal(*node.body,newsymtab);
	std::cout << "class " << node.getName() << " : nilep_type {\n";
	/* Local variables should be declared here */
	std::cout << " nile_t *call(";
	for(vars_t::const_iterator i=vars->begin();
			i!=vars->end();
			++i) 
		std::cout << "nile_t *nile_" << *i << " ";
	std::cout << ") {";
	emitC(*node.body,&newsymtab);
	std::cout << ";}\n}\n\n";
}

void emitC(block_t &node, vars_t *symtab)
{
	std::cout << "new closure_" << myid << "(this)";
}

void emitCglobal(block_t &node, vars_t *symtab)
{
	vars_t vars;
	vars_t newsymtab;
	for(container_t::iterator i=sentences.begin();
			i!=sentences.end();
			++i) {
		vars_t tmp = (*i)->getVars();
		vars.insert(tmp.begin(),tmp.end());
	}

	/* Generate the code */
	vars_t locals;
	for(vars_t::iterator i=vars.begin();
			i!=vars.end();
			++i) {
		/* New symbol ?*/
		if (symtab->find(*i) == symtab->end()) {
			locals.insert(*i);
		}
	}
	newsymtab = vars;
	newsymtab.insert(symtab->begin(),symtab->end());
	for(container_t::iterator i=sentences.begin();
			i!=sentences.end();
			++i) {
		(*i)->emitCglobal(&newsymtab);
	}
	std::cout << "struct closure_" << myid 
		  << " : public nile_t {\n"
		  << " nile_t *parent;\n";
	for(vars_t::iterator i=locals.begin();
			i!=locals.end();
			++i) {
		std::cout << " nile_t *nile_" << *i << ";\n";
	}
	std::cout << " closure_" << myid << "(nile_t *parent_)"
		  << " : parent(parent_) {}\n"
		  << " nile_t *call() {\n";
	for(container_t::iterator i=sentences.begin();
			i!=sentences.end();
			++i) {
		std::cout << "  ";
		(*i)->emitC(&newsymtab);
		std::cout << ";\n";
	}
	std::cout << " }\n};\n";
}
