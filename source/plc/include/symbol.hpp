#ifndef SYMBOL_HPP
#define SYMBOL_HPP
#include <string>
#include <memory>
#include <map>

namespace plc {

class analytic_value;

class symbol {
public:
	std::u32string const name;
	std::shared_ptr<analytic_value> const value;
	bool const is_variable;
	bool const is_local;
	bool const is_extern;
	//is unbound if isVariable && value.get() == nullptr

	symbol(std::u32string const & name, std::shared_ptr<analytic_value> const & value, bool isVariable, bool isLocal = true, bool isExtern = false);
	symbol & operator=(symbol const & other) = delete;
	symbol delocalize() const;
};

}

#endif //SYMBOL_HPP
