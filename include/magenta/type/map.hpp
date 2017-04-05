/**
 * @file magenta/map.hpp
 * @copyright Copyleft zukonake
 * @license Distributed under GNU General Public License Version 3
 */

#pragma once

#include <magenta/type/type.hpp>
#include <magenta/type/staticType.hpp>

namespace magenta
{

class VariableInterface;

class Map : public StaticType< MAP, MapValue >
{
public:
	using StaticType< MAP, MapValue >::operator;
private:
};

}
