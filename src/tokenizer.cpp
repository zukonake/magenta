#include <vector>
#include <string>
//
#include <magenta/tokenizer.hpp>

namespace Magenta::Tokenizer
{

CharacterType determineCharacterType( unsigned char const &character ) noexcept
{
	switch( ASCIITypes[ character ])
	{
		case 'L':
			return CharacterType::LETTER;
		case 'S':
			return CharacterType::SIGN;
		case 'D':
			return CharacterType::DIGIT;
		case 'W':
			return CharacterType::WHITESPACE;
		default:
		case 'I':
			return CharacterType::IRRELEVANT;
	}
}

std::vector< Token > tokenize( std::string const &data )
{
	std::vector< Token > returnValue;

	Token buffer = { "", IRRELEVANT };

	for( auto iCharacter : data )
	{
		CharacterType type = determineCharacterType( iCharacter );
		
		switch( type )
		{
			case CharacterType::LETTER:
				if( buffer.type != IDENTIFIER )
				{
					if( buffer.type != IRRELEVANT )
					{
						returnValue.push_back( buffer );
					}
					buffer.value = iCharacter;
				   	buffer.type = IDENTIFIER;
				}
				else
				{
					buffer.value += iCharacter;
				}
				break;

			case CharacterType::SIGN:
				if( buffer.type != IRRELEVANT )
				{
					returnValue.push_back( buffer );
				}
				buffer.value = iCharacter;
				buffer.type = OPERATOR;
				break;

			case CharacterType::DIGIT:
				if( buffer.type != IDENTIFIER &&
					buffer.type != NUMBER )
				{
					if( buffer.type != IRRELEVANT )
					{
						returnValue.push_back( buffer );
					}
					buffer.value = iCharacter;
					buffer.type = NUMBER;
				}
				else
				{
					buffer.value += iCharacter;
				}
				break;

			case CharacterType::WHITESPACE:
				if( buffer.type != IRRELEVANT )
				{
					returnValue.push_back( buffer );
				}
				buffer.value = iCharacter;
				buffer.type = WHITESPACE;
				break;

			case CharacterType::IRRELEVANT:
				if( buffer.type != IRRELEVANT )
				{
					returnValue.push_back( buffer );
				}
				buffer.type = IRRELEVANT;
				break;
		}
	}
	if( buffer.type != IRRELEVANT )
	{
		returnValue.push_back( buffer );
	}
	return returnValue;
}

}
