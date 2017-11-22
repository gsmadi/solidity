/*
	This file is part of solidity.

	solidity is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	solidity is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with solidity.  If not, see <http://www.gnu.org/licenses/>.
*/
/**
 * Optimiser component that performs function inlining.
 */
#pragma once

#include <libsolidity/inlineasm/AsmDataForward.h>
#include <libsolidity/inlineasm/AsmAnalysisInfo.h>

#include <boost/variant.hpp>
#include <boost/optional.hpp>

#include <set>

namespace dev
{
namespace julia
{

/**
 * Optimiser component that modifies an AST in place, inlining functions that can be
 * inlined inside functional expressions, i.e. functions that
 *  - return a single value
 *  - have a body like r := <functional expression>
 *  - neither reference themselves nor r in the right hand side
 *
 * This component can only be used on sources with unique names.
 */
class FunctionalInliner
{
public:
	FunctionalInliner(solidity::assembly::Block& _block):
		m_block(_block)
	{}

	void run();

private:
	void analyse();
	void execute();

//	Statement operator()(solidity::assembly::Literal const& _literal);
//	Statement operator()(solidity::assembly::Instruction const& _instruction);
//	Statement operator()(solidity::assembly::Identifier const& _identifier);
//	Statement operator()(solidity::assembly::FunctionalInstruction const& _instr);
//	Statement operator()(solidity::assembly::FunctionCall const&);
//	Statement operator()(solidity::assembly::Label const& _label);
//	Statement operator()(solidity::assembly::StackAssignment const& _assignment);
//	Statement operator()(solidity::assembly::Assignment const& _assignment);
//	Statement operator()(solidity::assembly::VariableDeclaration const& _varDecl);
//	Statement operator()(solidity::assembly::Switch const& _switch);
//	Statement operator()(solidity::assembly::FunctionDefinition const&);
//	Statement operator()(solidity::assembly::ForLoop const&);
//	Statement operator()(solidity::assembly::Block const& _block);

	std::map<std::string, solidity::assembly::FunctionDefinition const*> m_inlinableFunctions;

	solidity::assembly::Block const& m_block;
};


}
}
