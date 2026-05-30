#pragma once
#include <vector>

struct Node {
  virtual ~Node() = default;
};

struct LoopStmt : Node {
  int quantidade_loop;
  std::vector<Node *> bloco_codigo;
  LoopStmt(int _quantia, std::vector<Node *> _bloco)
      : quantidade_loop(_quantia), bloco_codigo(_bloco) {}
};

struct DireitaNode : Node {};
struct EsquerdaNode : Node {};
struct MaisNode : Node {};
struct MenosNode : Node {};
struct PontoNode : Node {};
struct VirgulaNode : Node {};
