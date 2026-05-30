#include "./write_bytecode.hpp"
#include <cstddef>
#include <exception>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void write_bytecode(std::string filename, std::vector<unsigned int> bytecode) {
  try {
    std::ofstream file(filename, std::ios::binary);
    file.exceptions(std::ofstream::failbit | std::ofstream::badbit);
    file.write((char *)bytecode.data(), sizeof(unsigned int) * bytecode.size());
    file.close();
  } catch (std::exception &e) {
    std::cerr << e.what() << '\n';
    exit(EXIT_FAILURE);
  }
}
