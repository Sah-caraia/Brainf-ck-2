#include "./get_lines.hpp"
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

std::string get_filelines(std::string filename) {
  if (!str_ends_with(filename, ".bf") && !str_ends_with(filename, ".bf2") &&
      !str_ends_with(filename, "bfuck2")) {
    std::cerr << "Error: \"" << filename << "\" is not a BrainFuck2 valid file."
              << '\n';
    std::cerr << "Valid file examples: " << '\n';
    std::cerr << "  code.bf" << '\n';
    std::cerr << "  code.bf2" << '\n';
    std::cerr << "  code.bfuck2";
    throw std::runtime_error("");
  }
  std::vector<std::string> lines;
  std::ifstream file(filename);
  if (!file.is_open()) {
    throw std::runtime_error("Error: File not found.");
  }

  std::string conteudo(std::istreambuf_iterator<char>(file),
                       std::istreambuf_iterator<char>{});

  return conteudo;
}
