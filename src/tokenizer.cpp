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
				if( buffer.type != IDENTIFIER && buffer.type != STRING )
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
				if( buffer.type != IRRELEVANT && buffer.type != STRING )
				{
					returnValue.push_back( buffer );
				}
				if( buffer.type == STRING )
				{
					buffer.value += iCharacter;
					if( iCharacter == buffer.value[0] )
					{
						returnValue.push_back( buffer );
						buffer.value = "";
						buffer.type = IRRELEVANT;
					}
				}	
				else if( iCharacter == '\'' || iCharacter == '\"' )
				{
					buffer.value = iCharacter;
					buffer.type = STRING;
				}
				else
				{
					buffer.value = iCharacter;
					buffer.type = OPERATOR;
				}
				break;

			case CharacterType::DIGIT:
				if( buffer.type != IDENTIFIER &&
					buffer.type != NUMBER &&
					buffer.type != STRING )
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
				if( buffer.type == STRING )
				{
					buffer.value += iCharacter;
				}
				else
				{
					buffer.value = iCharacter;
					buffer.type = WHITESPACE;
				}
				break;

			case CharacterType::IRRELEVANT:
				if( buffer.type == STRING )
				{
					buffer.value += iCharacter;
				}
				else if( buffer.type != IRRELEVANT )
				{
					returnValue.push_back( buffer );
					buffer.type = IRRELEVANT;
				}
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
