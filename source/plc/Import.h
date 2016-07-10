#ifndef IMPORT_H
#define IMPORT_H

#include "Statement.h"

class Import :
	public Statement {
public:
	Import();
	~Import();
	static std::unique_ptr<Statement> Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg);
};

#endif //IMPORT_H
