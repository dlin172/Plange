#ifndef CORRELATED_GRAMMAR_HPP
#define CORRELATED_GRAMMAR_HPP

#include <map>
#include <set>

#include "erased.hpp"

#include "parlex/precedence_collection.hpp"

#include "parlex/detail/behavior.hpp"
#include "parlex/detail/grammar_base.hpp"
#include "parlex/detail/state_machine.hpp"
#include "parlex/detail/string_terminal.hpp"


namespace parlex {
struct builder;

namespace behavior {

class node;

} // namespace behavior

namespace detail {

struct node;
class builtins_t;

// you must first create all the productions objects
// then create the behaviors
// then call set_behavior on each reference
class grammar : public grammar_base {
public:
	struct production {
		production(std::string const & id, filter_function const & filter, associativity assoc);
		behavior::node const & get_behavior() const;
		recognizer const & get_recognizer() const;
	private:
		friend class grammar;
		state_machine machine;
		std::unique_ptr<behavior::node> behavior;
		void set_behavior(erased<behavior::node> const & behavior);
	};

	grammar(builder const & grammarDefinition);
	grammar(grammar const & copy) = delete;
	virtual ~grammar() = default;

	state_machine_base const& get_main_state_machine() const override;
	std::map<std::string, state_machine_base const *> get_state_machines() const override;
	state_machine_base const& get_state_machine(std::string const & id) const override;
	string_terminal const& get_literal(std::string const & id) const override;
	bool does_precede(recognizer const * lhs, recognizer const * rhs) const override;
	precedence_collection get_precedences() const override;
protected:
	production const & get_production(std::string const & id) const;
private:
	std::map<std::string, production> productions;
	std::string const root_id;
	std::map<std::string, string_terminal> literals;
	std::map<recognizer const *, std::set<recognizer const *>> precedences;

	string_terminal& get_or_add_literal(std::u32string const & contents);
	recognizer const& get_recognizer(std::string const & id) const;
	erased<behavior::node> get_behavior(node const & b);
};

} // namespace detail
} // namespace parlex

#endif //CORRELATED_GRAMMAR_HPP