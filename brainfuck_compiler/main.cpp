#include "./src/core/bytecode_generator/bytecode_generator.hpp"
#include "./src/core/lexer/lexer.hpp"
#include "./src/core/parser/parser.hpp"
#include "./src/get_lines/get_lines.hpp"
#include "./src/models/nodes/nodes.hpp"
#include "./src/models/token/token.hpp"
#include "./src/utils/write_bytecode/write_bytecode.hpp"
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

int main(int argc, char **argv) {
  if (argc <= 1) {
    std::cout << "Error: No input files." << '\n';
    exit(-1);
  }

  try {
    std::string conteudo = get_filelines(argv[1]);
    std::vector<Token> tks = lexenize(conteudo);
    std::vector<Node *> nodes = parse_tokens(tks);
    std::vector<unsigned int> bytecode_generated = gerar_bytecode(nodes);
    write_bytecode("./exit.bfo", bytecode_generated);
    for (auto *node : nodes) {
      if (!node)
        continue;
      delete node;
    }
    return 0;

  } catch (std::runtime_error e) {
    std::cout << e.what() << '\n';
  } catch (...) {
    exit(-1);
  }
}
