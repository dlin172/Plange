#ifndef GRAMMAR_HPP
#define GRAMMAR_HPP

#include <map>
#include <string>

#include "parlex/state_machine.hpp"
#include "parlex/builtins/string_terminal.hpp"

namespace parlex {

namespace details {

class behavior_node;

}

class grammar {
public:
	grammar(std::string nameOfMain);
    grammar(std::string nameOfMain, std::map<std::string, std::shared_ptr<details::behavior_node>> const & trees, std::set<std::string> greedyNames);
    grammar(grammar const & other);
	state_machine const & get_main_production() const;
	grammar& operator=(grammar const &) = delete;
	void generate_cpp(std::string grammarName, std::string nameOfMain, std::ostream & cpp, std::ostream & hpp) const;
	std::map<std::string, state_machine> const & get_productions() const;
	state_machine & add_production(std::string id, size_t acceptStateCount);
	state_machine & add_production(std::string id, size_t acceptStateCount, filter_function const & filter);
	builtins::string_terminal & add_literal(std::u32string contents);
private:
	std::string main_production_name;
	std::map<std::string, state_machine> productions;
	std::list<builtins::string_terminal> literals;

};

}

#endif
