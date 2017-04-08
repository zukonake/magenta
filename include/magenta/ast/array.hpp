/**
 * @file magenta/array.hpp
 * @copyright Copyleft zukonake
 * @license Distributed under GNU General Public License Version 3
 */

#pragma once

#include <vector>
//
#include <magenta/ast/type.hpp>
#include <magenta/ast/staticType.hpp>

namespace magenta
{

class NodeInterface;

typedef std::vector< NodeInterface * > ArrayValue;
typedef StaticType< ARRAY, ArrayValue > Array;

}
