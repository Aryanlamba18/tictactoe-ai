#ifndef MINIMAX_X
#define MINIMAX_X

#include <unordered_map>

extern std::unordered_map<char, int> scores;

int minimax(char grid[3][3], int depth, bool ismaximising);
void Bestmove();

#endif