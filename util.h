#include <iostream>
#include <fstream>

// ************ ERROR HANDLING ************
struct CommandLineException
{
       CommandLineException()
   {
        std::cout << std::endl;
        std::cout << "Incorrect command line arguments." << std::endl;
        std::cout << "Please specify the input and output with the following format:" << std::endl;
        std::cout << "Sudoku {filename}" << std::endl;
   }
};

struct FileException {

    FileException(const std::string file) {
    std::cout << std::endl << "Error reading file '" << file << "'" << std::endl;
  }
};