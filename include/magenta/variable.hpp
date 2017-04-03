/**
 * @file magenta/variable.hpp
 * @copyright Copyleft zukonake
 * @license Distributed under GNU General Public License Version 3
 */

#pragma once

#include <string>

namespace Magenta
{

class VariableInterface { }

template< typename T >
class Variable : public VariableInterface
{
public:
	Variable( T const &value );
	Variable( Variable< T > const &that );

	~Variable() = default;

	Variable &operator=( T const &value );
	Variable &operator=( Variable< T > const &that );
private:
	std::string mName;
	T mValue;
};

}
