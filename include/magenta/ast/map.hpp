/**
 * @file magenta/map.hpp
 * @copyright Copyleft zukonake
 * @license Distributed under GNU General Public License Version 3
 */

#pragma once

#include <string>
#include <unordered_map>
//
#include <magenta/type/type.hpp>
#include <magenta/type/staticType.hpp>

namespace magenta
{

class VariableInterface;

typedef std::unordered_map< std::string, VariableInterface * > mapValue;

class Map : public StaticType< MAP, MapValue >
{
public:
	using StaticType< MAP, MapValue >::operator;
private:
};

}
