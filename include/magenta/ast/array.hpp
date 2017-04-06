/**
 * @file magenta/array.hpp
 * @copyright Copyleft zukonake
 * @license Distributed under GNU General Public License Version 3
 */

#pragma once

#include <vector>
//
#include <magenta/type/type.hpp>
#include <magenta/type/staticType.hpp>

namespace magenta
{

class VariableInterface;

typedef std::vector< VariableInterface * > ArrayValue;

class Array : public StaticType< ARRAY, ArrayValue >
{
public:
	using StaticType< ARRAY, ArrayValue >::operator;
private:
};

}
