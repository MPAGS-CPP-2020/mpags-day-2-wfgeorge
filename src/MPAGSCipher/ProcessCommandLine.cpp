#include "ProcessCommandLine.hpp"

bool processCommandLine( const std::vector<std::string>& cmdLineArgs, bool& helpRequested, bool& versionRequested, std::string& inputFile, std::string& outputFile )
{
  /* process command line arguments storing options in referenced objects

  cmdLineArgs:      Vector of strings containing arguments
  helpRequested:    Flag to store whether help requested
  versionRequested: Flag to store whether version number queried
  inputFile:        String to store name of input text file
  outputFile:       String to store name of output text file

  return: returns 0 if arguments processed sucessfully
  */
  
  // Add a typedef that assigns another name for the given type for clarity
  typedef std::vector<std::string>::size_type size_type;
  const size_type nCmdLineArgs {cmdLineArgs.size()};

  // Loop over command line arguments 
  // Ignore zeroth element, as we know this to be the program name
  for (size_type i {1}; i < nCmdLineArgs; ++i) {

    if (cmdLineArgs[i] == "-h" || cmdLineArgs[i] == "--help") {
      helpRequested = true;
    }
    else if (cmdLineArgs[i] == "--version") {
      versionRequested = true;
    }
    else if (cmdLineArgs[i] == "-i") {
      // Handle input file option
      // Next element is filename unless -i is the last argument
      if (i == nCmdLineArgs-1) {
      	std::cerr << "[error] -i requires a filename argument" << std::endl;
      	// exit main with non-zero return to indicate failure
      	exit(1);
      }
      else {
	      // Got filename, so assign value and advance past it
      	inputFile = cmdLineArgs[i+1];
      	++i;
      }
    }
    else if (cmdLineArgs[i] == "-o") {
      // Handle output file option
      // Next element is filename unless -o is the last argument
      if (i == nCmdLineArgs-1) {
      	std::cerr << "[error] -o requires a filename argument" << std::endl;
      	// exit main with non-zero return to indicate failure
      	exit(1);
      }
      else {
      	// Got filename, so assign value and advance past it
      	outputFile = cmdLineArgs[i+1];
      	++i;
      }
    }
    else {
      // Have an unknown flag to output error message and return non-zero
      // exit status to indicate failure
      std::cerr << "[error] unknown argument '" << cmdLineArgs[i] << "'\n";
      exit(1);
    }
  }  
  return 0;
}
