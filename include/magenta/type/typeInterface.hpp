/**
 * @file magenta/typeInterface.hpp
 * @copyright Copyleft zukonake
 * @license Distributed under GNU General Public License Version 3
 */

#pragma once

#include <magenta/type/type.hpp>

namespace magenta
{

class TypeInterface
{
public:
	virtual constexpr Type getType() const noexcept = 0;
}

}
