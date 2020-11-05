// Contains implementation of transformChar() function 

#include "TransformChar.hpp"

// Standard Library includes
#include <string>

// For std::isalpha and std::isupper
#include <cctype>

std::string transformChar( const char in_char ){

  /* take an input char and return transliterated version as string:
      - convert letter to uppercase
      - ignore non-alphanumeric chars
      - change numbers to words

  const char in_char: char to transliterate

  return: string with transliterated char
  */

  std::string inputText{""};

  // Uppercase alphabetic characters
  if (std::isalpha(in_char)) {
    inputText += std::toupper(in_char);
    return inputText;
  }

  // Transliterate digits to English words
  switch (in_char) {
    case '0':
	    inputText += "ZERO";
	    break;
    case '1':
	    inputText += "ONE";
	    break;
    case '2':
	    inputText += "TWO";
	    break;
    case '3':
	    inputText += "THREE";
    	break;
    case '4':
    	inputText += "FOUR";
    	break;
    case '5':
    	inputText += "FIVE";
    	break;
    case '6':
    	inputText += "SIX";
    	break;
    case '7':
    	inputText += "SEVEN";
    	break;
    case '8':
    	inputText += "EIGHT";
    	break;
    case '9':
	    inputText += "NINE";
    	break;
    }
    
    return inputText;
    // If the character isn't alphabetic or numeric, DONT add it.
    // Our ciphers can only operate on alphabetic characters.
}