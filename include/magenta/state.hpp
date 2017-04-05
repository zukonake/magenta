/**
 * @file magenta/state.hpp
 * @copyright Copyleft zukonake
 * @license Distributed under GNU General Public License Version 3
 */

#pragma once

#include <cstdint>
#include <string>
//
#include <magenta/table.hpp>
#include <magenta/interpreter.hpp>

namespace magenta
{

class State : public Interpreter
{
public:
	template< typename T >
	Variable< T > &getVariable( std::string const &name );
	Table &getEnvironment() noexcept;
private:
	Table mEnvironment;
};

}
