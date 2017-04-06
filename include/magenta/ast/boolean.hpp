/**
 * @file magenta/boolean.hpp
 * @copyright Copyleft zukonake
 * @license Distributed under GNU General Public License Version 3
 */

#pragma once

#include <magenta/type/type.hpp>
#include <magenta/type/staticType.hpp>

namespace magenta
{

typedef bool BooleanValue;

class Boolean : public StaticType< BOOLEAN, BooleanValue >
{
public:
	using StaticType< BOOLEAN, BooleanValue >::operator;
private:
};

}
