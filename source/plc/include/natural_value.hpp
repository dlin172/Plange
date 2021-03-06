#ifndef NATURAL_VALUE_HPP
#define NATURAL_VALUE_HPP

#pragma warning(push, 0)
#include <llvm/IR/Value.h>
#pragma warning(pop)

#include "analytic_value.hpp"

#include <memory>

namespace plc {

class natural_value : public analytic_value {
	struct value_deleter
	{
		void operator()(llvm::Value * ptr) const;
	};

public:
	explicit natural_value(llvm::Value * llvmValue);

	// this value is statically known if llvm_value is non-null 
	std::unique_ptr<llvm::Value, value_deleter> const llvm_value;
	std::map<std::string, std::unique_ptr<analytic_value>> get_constrained_symbols() const final;

	natural_value * collapse() override;

};

}

#endif //NATURAL_VALUE_HPP