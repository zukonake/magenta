/**
 * @file magenta/typeOf.hpp
 * @copyright Copyleft zukonake
 * @license Distributed under GNU General Public License Version 3
 */

#pragma once

#include <magenta/type/type.hpp>
#include <magenta/type/staticType.hpp>

namespace magenta
{

class TypeOf : public StaticType< TYPE_OF, Type >
{
public:
	using StaticType< TYPE_OF, Type >::operator;
private:
};

}
