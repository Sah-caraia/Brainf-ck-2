#include "./parser.hpp"
#include "../../models/nodes/nodes.hpp"
#include "../../models/token/token.hpp"
#include "../../models/token_types/token_types.hpp"
#include <cstddef>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

// FUNCAO AUXILIAR
// ↓↓↓
void add_on_vec(vector<Node *> *nodes, Token token) {
  switch (token.tipo) {
  case TokenType::MAIS:
    nodes->push_back(new MaisNode());
    break;
  case TokenType::MENOS:
    nodes->push_back(new MenosNode());
    break;
  case TokenType::PONTO:
    nodes->push_back(new PontoNode());
    break;
  case TokenType::VIRGULA:
    nodes->push_back(new VirgulaNode());
    break;
  case TokenType::DIREITA:
    nodes->push_back(new DireitaNode());
    break;
  case TokenType::ESQUERDA:
    nodes->push_back(new EsquerdaNode());
    break;
  default:
    break;
  }
}

vector<Node *> parse_tokens(std::vector<Token> tokens) {
  vector<Node *> nodes;

  size_t i = 0;
  size_t lentokens = tokens.size();
  while (i < lentokens) {
    // vefifica se é numero (loop statement)
    if (tokens[i].tipo == TokenType::NUMERO) {
      LoopStmt loop(0, {});
      int contador_loop = stoi(tokens[i].valor);
      loop.quantidade_loop = contador_loop;
      i++;
      // se nao tiver ":", dá um alerf
      if (tokens[i].tipo != TokenType::DS_PONTOS) {
        throw runtime_error("Error: No \":\" after number in loop statement.");
      }
      i++;
      while (tokens[i].tipo != TokenType::PT_VIRGULA) {
        if (i >= lentokens) {
          throw runtime_error("Error: No \";\" after loop block.");
        }
        add_on_vec(&loop.bloco_codigo, tokens[i]);
        i++;
        continue;
      }
      nodes.push_back(new LoopStmt(loop.quantidade_loop, loop.bloco_codigo));
      i++;
      continue;
    } else {
      add_on_vec(&nodes, tokens[i]);
      i++;
      continue;
    }
  }
  return nodes;
}
