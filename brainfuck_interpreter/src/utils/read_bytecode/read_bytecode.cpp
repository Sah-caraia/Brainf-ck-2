#include "./read_bytecode.hpp"
#include <fstream>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <vector>

bool str_ends_with(const std::string &str, const std::string &suffix) {
  return str.size() >= suffix.size() &&
         str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

std::vector<unsigned int> read_bytecode(std::string filename) {
  if (!str_ends_with(filename, ".bfo")) {
    std::cerr << "Error: \"" << filename
              << "\" is not a BrainFuck2 Compiled valid file." << '\n';
    std::cerr << "Valid file example: " << '\n';
    std::cerr << "  code.bfo" << '\n';
    throw std::runtime_error("");
  }
  std::ifstream file(filename, std::ios::binary);
  if (!file.is_open()) {
    throw std::runtime_error("Error: File does not exists.");
  }

  std::vector<unsigned int> instructions;
  unsigned int act_intruc;

  while (file.read((char *)&act_intruc, sizeof(unsigned int))) {
    instructions.push_back(act_intruc);
  }

  return instructions;
}
