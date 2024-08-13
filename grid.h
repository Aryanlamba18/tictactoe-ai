#ifndef GRID_H
#define GRID_H

extern char grid[3][3];
extern char ai;
extern char human;
extern bool humanplaying;

void printgrid(char grid[3][3]);
bool win(char grid[3][3]);
bool isMovesLeft(char grid[3][3]);
char checkWinner(char grid[3][3]);


#endif

