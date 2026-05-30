#pragma once
#include "../../models/nodes/nodes.hpp"
#include "../../models/token/token.hpp"
#include <vector>

std::vector<Node *> parse_tokens(std::vector<Token> tokens);
