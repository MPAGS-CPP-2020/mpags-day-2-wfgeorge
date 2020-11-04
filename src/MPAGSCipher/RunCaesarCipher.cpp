// Contains implementation of transformChar() function 

#include "RunCaesarCipher.hpp"

// Standard Library includes
#include <string>
#include <vector>

std::string runCaesarCipher( const std::string& inputText, const size_t key, const bool encrypt ){

    // Create the alphabet container and output string
    const std::vector<char> alpha{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    std::string outputText{""};

    //Shift letters to right in alphabet if encrypting or left if decrypting
    signed int encryptSign{1};
    if(!encrypt) encryptSign = -1;

    // Loop over the input text
    for(std::string::size_type inputIndex = 0; inputIndex < inputText.size(); inputIndex++){

        signed int new_index{0};

        // For each character find the corresponding position in the alphabet
        for(int currentIndex = 0; currentIndex < 26; currentIndex++){
            if(inputText[inputIndex] == alpha[currentIndex]){
                //Found input char; now shift index of letter by key (encryptSign determines direction of shift)
                new_index = (currentIndex + encryptSign*key);
                
                //if new_index is >25 then wrap around to start
                if(new_index > 25) new_index = new_index % 26;
                //if new_index is negative, wrap it back to end of alphabet
                if(new_index < 0) new_index += 26;
            }
        }

        // Determine the new character and add it to the output string
        char encryptedChar{alpha[new_index]};
        outputText += encryptedChar;
    }

    // Finally (after the loop), return the output string 
    return outputText;
}