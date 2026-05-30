#include "./src/interpreter/interpreter.hpp"
#include "./src/utils/read_bytecode/read_bytecode.hpp"
#include <cstddef>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

int main(int argc, char **argv) {

  if (argc < 2) {
    throw std::runtime_error("Error: No Input Files!");
    exit(-1);
  }

  try {
    std::vector<unsigned int> bytecode = read_bytecode(argv[1]);
    interpreter(bytecode);
  } catch (std::exception &e) {
    std::cerr << e.what() << '\n';
    exit(-1);
  }
  return 0;
}
