#include "parlex/cpp_generator.hpp"

#include <sstream>

#include "parlex/builder.hpp"
#include "parlex/builtins.hpp"
#include "parlex/behavior.hpp"

namespace parlex {

static std::string get_include_guard_name(std::string name) {
	for (auto & c : name) c = toupper(c);
	return name + "_HPP";
}

static std::string get_include_guard_open(std::string const & include_guard_name) {
	return "#ifndef " + include_guard_name + "\n#define" + include_guard_name + "\n";
}

static std::string get_include_guard_close(std::string const & include_guard_name) {
	return "#endif //" + include_guard_name;
}

static std::string add_include_guard(std::string const & text, std::string const & production_name) {
	auto include_guard_name = get_include_guard_name(production_name);
	return get_include_guard_open(include_guard_name) + "\n" + text + "\n" + get_include_guard_close(include_guard_name);
}

static std::string get_namespaces_open(std::vector<std::string> const & namespaces) {
	std::string result;
	for (auto const & n : namespaces) {
		result += "namespace " + n + " {";
	}
	return result;
}

static std::string get_namespaces_close(std::vector<std::string> const & namespaces) {
	std::string result;
	for (auto i = namespaces.rbegin(); i != namespaces.rend(); ++i) {
		result += "} // " + *i + "\n";
	}
	return result;
}

static std::string add_namespaces(std::string const & text, std::vector<std::string> const & namespaces) {
	return get_namespaces_open(namespaces) + "\n" + text + "\n" + get_namespaces_close(namespaces);
}

//returns the type name to be used in the tree
//buffer is modified by adding dependency types
static std::string build_type(std::stringstream & buffer, builder::node const & node, std::string const & name) {
	/////////////////////////////////////////////////////////////////////////////////////////////////
#define DO_AS(name)                                                                             \
		auto const * as_##name = dynamic_cast<builder::name##_t const *>(&node);                  \
		if (as_##name != nullptr)                                                                 \
///////////////////////////////////////////////////////////////////////////////////////////////////

	if (node.tag != "") {
		std::string childName = node.tag;
		if (name != "") {
			childName = name + "_" + childName;
		}
		return build_type(buffer, node, name + "_" + node.tag);
	}
	DO_AS(literal) {
		return "";
	}
	DO_AS(reference) {
		return "";
	}
	DO_AS(choice) {
		std::stringstream result;
		result << "std::variant<";
		for (size_t i = 0; i < node.children.size(); ++i) {
			builder::node const & child = *node.children[i];
			auto childString = build_type(buffer, child, "");
			if (childString == "") {
				result << "std::integral_constant<" << std::to_string(i) << ">";
			} else {
				result << childString;
			}
		}
		result << ">";
	}
	DO_AS(optional) {
		builder::node const & child = *node.children[0];
		auto childString = build_type(buffer, child, "");
		if (childString == "") {
			return "bool";
		}
		return "std::optional<" + childString + ">";
	}
	DO_AS(repetition) {
		builder::node const & child = *node.children[0];
		auto childString = build_type(buffer, child, "");
		if (childString == "") {
			return "int";
		}
		return "std::vector<" + childString + ">";
	}
	DO_AS(sequence) {

	}

#undef DO_AS

}


static std::string generate_grammar_hpp_code(std::string const & name, builder::grammar const & g, std::vector<std::string> const & namespaces) {
	std::stringstream result;
	result << "class " << name << " : public builder::grammar {\n";
	result << "public:\n";
	for (auto const & production : g.productions) {
		result << "\tbuilder::production " << production.id << ";\n";
	}
	result << "\n";
	result << "\t";
	throw std::logic_error("not implemented");
}

static std::string generate_grammar_cpp_behavior_code(builder::node const * node, int indentation) {
	std::stringstream result;

	/////////////////////////////////////////////////////////////////////////////////////////////////
#define DO_AS(name)                                                                             \
		auto const * as_##name = dynamic_cast<builder::name##_t const *>(node);                  \
		if (as_##name != nullptr)                                                                 \
///////////////////////////////////////////////////////////////////////////////////////////////////

	std::string indentString("\t", indentation);
	bool wasLeaf = false;
	DO_AS(literal) {
		result << indentString << "literal(" << node->tag << "U" << as_literal->id << ")";
		wasLeaf = true;
	}
	DO_AS(reference) {
		result << indentString << "reference(" << as_reference->id << ")";
		wasLeaf = true;
	}
	if (!wasLeaf) {
#define DO_NON_LEAF_AS(name) DO_AS(name) { result << indentString << #name "(" << node->tag << "\n"; }
		DO_NON_LEAF_AS(choice);
		DO_NON_LEAF_AS(optional);
		DO_NON_LEAF_AS(repetition);
		DO_NON_LEAF_AS(sequence);
#undef  DO_NON_LEAF_AS

#undef DO_AS

		bool firstChild = true;
		for (erased<builder::node> const & child : node->children) {
			if (!firstChild) {
				result << ",\n";
			}
			result << generate_grammar_cpp_behavior_code(&*child, indentation + 1);
			firstChild = false;
		}
		result << "\n" << indentString << ")";
	}

	return result.str();
}


static std::string generate_grammar_cpp_code(std::vector<std::string> const & namespaces, builder::production const & p) {

}

static std::pair<std::string, std::string> generate(std::vector<std::string> const & namespaces, builder::production const & p) {
	//return std::make_pair(generate_hpp_code(namespaces, p), generate_cpp_code(namespaces, p));
}

std::string node_to_cpp(builder::node const & n, int indentLevel) {
	std::stringstream ss;

	auto add_tag = [&]()
	{
		if (n.tag != "") {
			ss << enquote(n.tag) << ", ";
		}
	};

#define DO_AS(name) auto const * as_##name = dynamic_cast<builder::name##_t const *>(&n); if (as_##name != nullptr)
	DO_AS(literal) {
		ss << "literal(";
		add_tag();
		ss << enquote(as_literal->id);
		ss << ")";
	}

	DO_AS(reference) {
		ss << "reference(";
		add_tag();
		ss << enquote(as_reference->id);
		ss << ")";
	}

	auto write_children = [&]()
	{		
		for (auto const & child : n.children) {
			ss << std::string('\t', indentLevel + 1);
			ss << node_to_cpp(*child, indentLevel + 1);
			if (&*child != &**n.children.rbegin()) {
				ss << ",";
			}
		}
	};

	DO_AS(choice) {
		ss << "choice(";
		add_tag();
		ss << "{\n";
		write_children();
		ss << std::string('\t', indentLevel) << "})";		
	}

	DO_AS(optional) {
		ss << "optional(";
		add_tag();
		ss << "\n";
		write_children();
		ss << std::string('\t', indentLevel) << ")";
	}

	DO_AS(repetition) {
		ss << "repetition(";
		add_tag();
		ss << "\n";
		write_children();
		ss << std::string('\t', indentLevel) << ")";
	}

	DO_AS(sequence) {
		ss << "sequence(";
		add_tag();
		ss << "{\n";
		write_children();
		ss << std::string('\t', indentLevel) << "})";
	}

	return ss.str();
}

std::string production_to_cpp(builtins_t const & builtins, builder::production const & p) {
	std::stringstream ss;
	ss << "production(" << enquote(p.id) << ", ";
	ss << node_to_cpp(*p.behavior, 2);
	bool needsPrecendences = p.precedences.size() > 0;
	bool needsFilter = p.filter != filter_function() || needsPrecendences;
	bool needsAssociativity = p.assoc != associativity::none || needsFilter;
	if (needsAssociativity) {
		ss << ",\n\t\tassociativity::";
		switch (p.assoc) {
		case associativity::any:
			ss << "any";
		case associativity::left:
			ss << "left";
		case associativity::none:
			ss << "none";
		case associativity::right:
			ss << "right";
		}
	}
	if (needsFilter) {
		ss << ", ";
		if (p.filter == builtins.longest) {
			ss << "builtins.longest";
		}
		else if (!p.filter) {
			ss << "filter_function()";
		}
		else {
			throw;
		}
	}
	if (needsPrecendences) {
		ss << ", {";
		for (auto const & precedence : p.precedences) {
			ss << enquote(precedence) << ", ";
		}
	}
	return ss.str();
}

std::string cpp_generator::generate(builtins_t const & builtins, builder::grammar const & g) {
	std::stringstream ss;
	ss << "parlex::builder::grammar(" << enquote(g.root_id) << ", {\n;";
	for (auto const & p : g.productions) {
		ss << production_to_cpp(builtins, p);
	}
	ss << "});";
	return ss.str();
}

} // namespace parlex
