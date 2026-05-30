#pragma once
#include "../token_types/token_types.hpp"
#include <string>

struct Token {
  TokenType tipo;
  std::string valor;

  Token(TokenType _tipo, std::string _valor) : tipo(_tipo), valor(_valor) {}
};
