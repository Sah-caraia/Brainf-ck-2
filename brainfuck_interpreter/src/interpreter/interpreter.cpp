#include "./interpreter.hpp"
#include "../models/char_types/char_types.hpp"
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int ponteiro = 0;
vector<unsigned char> posicoes;

void interpreter(std::vector<unsigned int> bytecode) {

  posicoes.resize(500, 0);

  for (const int &bt_atual : bytecode) {

    if (bt_atual == CharTypes::DOT) {
      std::cout << posicoes[ponteiro];
      continue;
    }

    else if (bt_atual == CharTypes::COMMA) {
      posicoes[ponteiro] = (unsigned char)getchar();
      continue;
    }

    else if (bt_atual == CharTypes::PLUS) {
      posicoes[ponteiro]++;
      continue;
    }

    else if (bt_atual == CharTypes::MINUS) {
      if (posicoes[ponteiro] <= 0) {
        continue;
      }
      posicoes[ponteiro]--;
      continue;
    }

    else if (bt_atual == CharTypes::MOVE_RIGHT) {
      ponteiro++;
      if (ponteiro >= (int)posicoes.size()) {
        posicoes.push_back(0);
      }
      continue;
    }

    else if (bt_atual == CharTypes::MOVE_LEFT) {
      if (ponteiro <= 0)
        continue;
      ponteiro--;
      continue;
    }

    else {
      continue;
    }
  }
}
