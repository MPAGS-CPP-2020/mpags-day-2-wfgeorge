# - Set CMake requirements then declare project
cmake_minimum_required(VERSION 3.2)
project(MPAGSCipher VERSION 0.1.0)

# - When Makefiles are generated, output all command lines by default
#   to see what compiler commands/flags are used
set(CMAKE_VERBOSE_MAKEFILE ON) 
#equivalent to 'make VERBOSE=1'

# - Set the C++ standard directly
#set(CMAKE_CXX_STANDARD 14)

# - Declare the build of mpags-cipher executable
add_executable(mpags-cipher 
    mpags-cipher.cpp
    MPAGSCipher/TransformChar.cpp
    MPAGSCipher/ProcessCommandLine.cpp
    MPAGSCipher/RunCaesarCipher.cpp
    )

target_include_directories(mpags-cipher
    PRIVATE MPAGSCipher
    )

# - Tell CMake which compiler flags we want to set
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wfatal-errors -Wshadow -pedantic")

# - Ensure that the in-use C++ compiler is capable of cpp features
#   CMake will add any necessary flags such as -std=gnu++11 
#   to the compile lines of C++ files in the target (mpags-cipher).
#   Easy and platform independent way to specify what we need the 
#   compiler to support
#   A FATAL_ERROR is issued if the compiler is not capable of the feature. 
target_compile_features(mpags-cipher
  PRIVATE cxx_auto_type cxx_range_for cxx_uniform_initialization
  )