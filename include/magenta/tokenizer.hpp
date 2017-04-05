/**
 * @file magenta/tokenizer.hpp
 * @copyright Copyleft zukonake
 * @license Distributed under GNU General Public License Version 3
 */

#pragma once

#include <vector>
#include <string>

namespace magenta::tokenizer
{

enum class CharacterType
{
	IRRELEVANT,
	LETTER,
	SIGN,
	DIGIT,
	WHITESPACE
};
							 // 129 because of trailing NULL terminator
const unsigned char ASCIITypes[ 129 ] =	
	"IIIIIIIIIIWIIIII" //0  - 15
	"IIIIIIIIIIIIIIII" //16 - 31
	"ISSSISSSSSSSISIS" //32 - 47
	"DDDDDDDDDDISSSSS" //48 - 63
	"ILLLLLLLLLLLLLLL" //64 - 79
	"LLLLLLLLLLLSSSSS" //80 - 95
	"ILLLLLLLLLLLLLLL" //96 -111
	"LLLLLLLLLLLSSSII";//112-127

enum TokenType
{
	IRRELEVANT,
	IDENTIFIER,
	OPERATOR,
	NUMBER,
	STRING,
	WHITESPACE
};

struct Token
{
	std::string value;
	TokenType type;
};

CharacterType determineCharacterType( unsigned char const &character ) noexcept;
std::vector< Token > tokenize( std::string const &data );

}
