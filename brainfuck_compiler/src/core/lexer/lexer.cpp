#include "./lexer.hpp"
#include "../../models/token/token.hpp"
#include "../../utils/char_utils/char_utils.hpp"
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

std::vector<Token> lexenize(std::string code) {
  std::vector<Token> tokens;

  size_t i = 0;
  size_t lencode = code.length();
  while (i < lencode) {

    if (code[i] == ' ') {
      i++;
      continue;
    }

    if (code[i] == '\n') {
      i++;
      continue;
    }

    if (eh_letra(code[i])) {
      i++;
      continue;
    }

    else if (code[i] == '>') {
      tokens.push_back(Token(TokenType::DIREITA, ">"));
      i++;
      continue;
    }

    else if (code[i] == '<') {
      tokens.push_back(Token(TokenType::ESQUERDA, "<"));
      i++;
      continue;
    }

    else if (code[i] == '+') {
      tokens.push_back(Token(TokenType::MAIS, "+"));
      i++;
      continue;
    }

    else if (code[i] == '-') {
      tokens.push_back(Token(TokenType::MENOS, "-"));
      i++;
      continue;
    }

    else if (code[i] == '.') {
      tokens.push_back(Token(TokenType::PONTO, "."));
      i++;
      continue;
    }

    else if (code[i] == ':') {
      tokens.push_back(Token(TokenType::DS_PONTOS, ":"));
      i++;
      continue;
    }

    else if (code[i] == ';') {
      tokens.push_back(Token(TokenType::PT_VIRGULA, ";"));
      i++;
      continue;
    }

    else if (code[i] == ',') {
      tokens.push_back(Token(TokenType::VIRGULA, ","));
      i++;
      continue;
    }

    else if (eh_numero(code[i])) {
      size_t comeco_num = i;
      while (i < lencode && eh_numero(code[i])) {
        i++;
        continue;
      }
      tokens.push_back(
          Token(TokenType::NUMERO, code.substr(comeco_num, i - comeco_num)));
    }

    else {
      std::cout << "Unkown character: " << code[i] << "\n";
      throw std::runtime_error("");
    }
  }
  return tokens;
}
