#include <iostream>
#include <boost/test/unit_test.hpp>
//
#include <magenta/tokenizer.hpp>

namespace Magenta::Tokenizer::Test
{

BOOST_AUTO_TEST_SUITE( tokenizerTest );

BOOST_AUTO_TEST_CASE( determineCharacterTypeTest00 )
{
	BOOST_CHECK( determineCharacterType( 'a' ) == CharacterType::LETTER );
	BOOST_CHECK( determineCharacterType( 'A' ) == CharacterType::LETTER );
	BOOST_CHECK( determineCharacterType( '2' ) == CharacterType::DIGIT );
	BOOST_CHECK( determineCharacterType( ' ' ) == CharacterType::IRRELEVANT );
	BOOST_CHECK( determineCharacterType( '\t' ) == CharacterType::IRRELEVANT );
	BOOST_CHECK( determineCharacterType( '*' ) == CharacterType::SIGN );
	BOOST_CHECK( determineCharacterType( ';' ) == CharacterType::SIGN );
	BOOST_CHECK( determineCharacterType( '}' ) == CharacterType::SIGN );
}

BOOST_AUTO_TEST_CASE( tokenizeTest00 )
{
	BOOST_CHECK_EQUAL( tokenize( "this is a test text" ).size(), 5 );
	BOOST_CHECK_EQUAL( tokenize( "this is a test text\n2" ).size(), 7 );
	BOOST_CHECK_EQUAL( tokenize( "test = 2ab-  34\n{\nasdf;\n}" ).size(), 13 );
}

BOOST_AUTO_TEST_SUITE_END();

}
