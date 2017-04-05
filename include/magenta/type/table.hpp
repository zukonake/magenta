/**
 * @file magenta/table.hpp
 * @copyright Copyleft zukonake
 * @license Distributed under GNU General Public License Version 3
 */

#pragma once

#include <magenta/type/type.hpp>
#include <magenta/type/staticType.hpp>

namespace magenta
{

class Table : public StaticType< TABLE, TableValue >
{
public:
	using StaticType< TABLE, TableValue >::operator;
private:
};

}
