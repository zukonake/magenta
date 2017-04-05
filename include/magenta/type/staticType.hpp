/**
 * @file magenta/staticType.hpp
 * @copyright Copyleft zukonake
 * @license Distributed under GNU General Public License Version 3
 */

#pragma once

#include <magenta/type/type.hpp>

namespace magenta
{

template< Type type, typename T >
class StaticType : public TypeInterface
{
public:
	explicit StaticType( T const &value );

	operator T() const noexcept;

	virtual constexpr Type getType() const noexcept override;

	T value;
}

}
