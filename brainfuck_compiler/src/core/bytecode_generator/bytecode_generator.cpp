#include "./bytecode_generator.hpp"
#include "../../models/char_types/char_types.hpp"
#include "../../models/nodes/nodes.hpp"
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <vector>

std::vector<unsigned int> GENERATED_BYTECODE;
std::vector<unsigned int> gerar_bytecode(std::vector<Node *> nodes) {
  size_t i = 0;
  size_t lennodes = nodes.size();

  while (i < lennodes) {

    if (nodes[i] == nullptr) {
      i++;
      continue;
    }
    if (auto *ponto = dynamic_cast<PontoNode *>(nodes[i])) {
      GENERATED_BYTECODE.push_back(CharTypes::DOT);
      i++;
      continue;
    }

    else if (auto *dir = dynamic_cast<DireitaNode *>(nodes[i])) {
      GENERATED_BYTECODE.push_back(CharTypes::MOVE_RIGHT);
      i++;
      continue;
    }

    else if (auto *esq = dynamic_cast<EsquerdaNode *>(nodes[i])) {
      GENERATED_BYTECODE.push_back(CharTypes::MOVE_LEFT);
      i++;
      continue;
    }

    else if (auto *mais = dynamic_cast<MaisNode *>(nodes[i])) {
      GENERATED_BYTECODE.push_back(CharTypes::PLUS);
      i++;
      continue;
    }

    else if (auto *menos = dynamic_cast<MenosNode *>(nodes[i])) {
      GENERATED_BYTECODE.push_back(CharTypes::MINUS);
      i++;
      continue;
    }

    else if (auto *virg = dynamic_cast<VirgulaNode *>(nodes[i])) {
      GENERATED_BYTECODE.push_back(CharTypes::COMMA);
      i++;
      continue;
    }

    else if (auto *loop = dynamic_cast<LoopStmt *>(nodes[i])) {
      for (int j = 0; j < loop->quantidade_loop; j++) {
        gerar_bytecode(loop->bloco_codigo);
      }
      i++;
      continue;
    }

    else {
      std::cout << "Unrecoginized node type: " << nodes[i];
      throw std::runtime_error("");
    }
  }
  return GENERATED_BYTECODE;
}
