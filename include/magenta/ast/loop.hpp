/**
 * @file magenta/ifElse.hpp
 * @copyright Copyleft zukonake
 * @license Distributed under GNU General Public License Version 3
 */

#pragma once

#include <magenta/ast/callable.hpp>

namespace magenta
{

class IfElse
{
public:
	virtual void call( Map const &environment ) const;
private:
	TypeInterface *mCondition;
	Table mIfBody;
	Table mElseBody;
};

}
