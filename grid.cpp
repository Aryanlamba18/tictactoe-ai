#include "grid.h"
#include<iostream>

char grid[3][3]={};
char ai='x';
char human='o';
bool humanplaying=true;

void printgrid(char grid[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            std::cout<<" ";
            if(grid[i][j]!=0){
                std::cout<<grid[i][j];
            }
            else{
                std::cout<<" ";
            }
            std::cout<<" ";
            if(j<2){ std::cout<<" | ";}
        }
        std::cout<<std::endl;
    }
}



bool win(char grid[3][3]){

    bool winner=false;
    winner=
              (grid[0][0] ==  grid[0][1]   && grid[0][1] == grid[0][2] && grid[0][0]!=0) || // Row 1
              (grid[1][0] ==  grid[1][1]   && grid[1][2] == grid[1][1] && grid[1][0]!=0) || // Row 2
              (grid[2][0] ==  grid[2][1]  && grid[2][2] == grid[2][1] && grid[2][0]!=0) || // Row 3
              (grid[0][0] ==  grid[1][0]   && grid[2][0] == grid[1][0] && grid[0][0]!=0) || // Column 1
              (grid[0][1] ==  grid[1][1]  && grid[2][1] == grid[1][1] && grid[0][1]!=0) || // Column 2
              (grid[0][2] ==  grid[1][2]  && grid[2][2] == grid[1][2] && grid[0][2]!=0) || // Column 3
              (grid[0][0] ==  grid[1][1]   && grid[2][2] == grid[1][1] && grid[0][0]!=0) || // Diagonal 1
              (grid[0][2] ==  grid[1][1]  && grid[2][0] == grid[1][1] && grid[0][2]!=0);   // Diagonal 2
    
    return winner;
}
bool isMovesLeft(char grid[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i][j] == 0)
                return true;
    return false;
}

char checkWinner(char grid[3][3]) {
    if (win(grid)) {
        // Check who won
        for (int i = 0; i < 3; i++) {
            if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][0] != 0)
                return grid[i][0]; // Return the winning character
            if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[0][i] != 0)
                return grid[0][i];
        }
        if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] != 0)
            return grid[0][0];
        if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[0][2] != 0)
            return grid[0][2];
    }
    return isMovesLeft(grid) ? 'n' : 't'; // Return 'T' for tie, 'N' for no result yet
}