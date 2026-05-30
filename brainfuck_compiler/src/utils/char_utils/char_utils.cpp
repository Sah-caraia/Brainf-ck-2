#include "./char_utils.hpp"

bool eh_numero(char ch) { return ch >= '0' && ch <= '9'; }
bool eh_letra(char ch) {
  return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}
