#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <iostream>
#include <string>
#include <vector>

bool processCommandLine( const std::vector<std::string>& cmdLineArgs, bool& helpRequested, bool& versionRequested, std::string& inputFile, std::string& outputFile, size_t& key, bool& encrypt );

#endif // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP