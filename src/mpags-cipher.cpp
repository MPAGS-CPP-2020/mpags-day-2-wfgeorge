#include "TransformChar.hpp"
#include "ProcessCommandLine.hpp"
#include "RunCaesarCipher.hpp"

// Standard Library includes
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// For std::isalpha and std::isupper
#include <cctype>

// Main function of the mpags-cipher program
int main(int argc, char* argv[])
{
  // Convert the command-line arguments into a more easily usable form
  const std::vector<std::string> cmdLineArgs {argv, argv+argc};

  // Options that might be set by the command-line arguments
  bool helpRequested {false};
  bool versionRequested {false};
  std::string inputFile {""};
  std::string outputFile {""};
  size_t key{0};
  bool encrypt{true};

  processCommandLine( cmdLineArgs, helpRequested, versionRequested, inputFile, outputFile, key, encrypt);

  if (helpRequested) {
    std::cout
      << "Usage: mpags-cipher [-i <file>] [-o <file>]\n\n"
      << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
      << "Available options:\n\n"
      << "  -h|--help        Print this help message and exit\n\n"
      << "  --version        Print version information\n\n"
      << "  -i FILE          Read text to be processed from FILE\n"
      << "                   Stdin will be used if not supplied\n\n"
      << "  -o FILE          Write processed text to FILE\n"
      << "                   Stdout will be used if not supplied\n\n"
      << "  -e BOOL          Encrypt text if BOOL == '1'/'TRUE' or decrypt if '0'/'FALSE'\n\n"
      << "  -k INT           Key to be used for encryption\n"
      << "                   Should be integer from 0-25\n\n";
    // Help requires no further action, so return from main
    // with 0 used to indicate success
    return 0;
  }

  // Like help, requires no further action,
  // so return from main with zero to indicate success
  if (versionRequested) {
    std::cout << "0.1.0" << std::endl;
    return 0;
  }

  if(key==0){
    std::cout << "No key entered. Text will be transliterated but no encryption will be used." << std::endl;
  }
  else{
    if(encrypt==true) std::cout << "Input will be encrypted with key " << key << std::endl;
    else std::cout << "Input will be decrypted with key " << key << std::endl;
  }

  // Initialise variables for processing input text
  char inputChar {'x'};
  std::string inputText {""};

  // Read in user input from stdin/file
  // Or read from stdin if no input file given
  if (!inputFile.empty()) {
    
    std::ifstream in_file {inputFile};
    bool okay_to_read = in_file.good();

    if(okay_to_read){
      while(in_file >> inputChar){
        inputText += transformChar(inputChar);
      }
    }
    else{
      std::cout << "[warning] input file ('"
              << inputFile
              << "') could not be opened.\n";
      return 1;
    }
    std::cout << "[INFO] Reading text from input file " << inputFile << std::endl;
  }
  else{
    // Loop over each character from user input
    // (until Return then CTRL-D (EOF) pressed)
    std::cout << "[warning] no input file given, using stdin.\n";
    while(std::cin >> inputChar){
      inputText += transformChar(inputChar);
    }
  }

  //Run input text through Caesar cipher and get output
  std::string outputText{runCaesarCipher(inputText, key, encrypt)};
  
  // Output the transliterated text
  // Either to output file or to stdout if no file specified
  if (!outputFile.empty()) {
    
    std::ofstream out_file {outputFile};
    bool okay_to_write = out_file.good();

    if(okay_to_write){
      out_file << outputText;
    }
    else{
      std::cout << "[warning] output file ('"
              << outputFile
              << "') could not be opened.\n";
      return 1;
    }
    std::cout << "[INFO] output text written to output file " << outputFile << std::endl;
  }
  else{
    //Print output to terminal
    std::cout << "[warning] no output file given, using stdout.\n";
    std::cout << outputText << std::endl;
  }

  // No requirement to return from main, but we do so for clarity
  // and for consistency with other functions
  return 0;
}
