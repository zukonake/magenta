/**
 * @file magenta/interpreter.hpp
 * @copyright Copyleft zukonake
 * @license Distributed under GNU General Public License Version 3
 */

#pragma once

#include <cstdint>
#include <string>
//
#include <magenta/table.hpp>

namespace Magenta
{

class State;

class Interpreter
{
public:
	
private:
	State &mState;

	std::string mFile;

	uint64_t mLineNumber;
};

}
