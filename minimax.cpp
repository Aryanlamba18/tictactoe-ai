#include "minimax.h"
#include "grid.h"
#include <algorithm>
#include <limits.h>
#include<iostream>

using namespace std;

std::unordered_map<char, int> scores = {
    {'x', 10},
    {'o', -10},
    {'t', 0}
};

int minimax(char grid[3][3],int depth,bool ismaximising){
    char result = checkWinner(grid); // Assuming win returns a string like "X", "O", or "tie"
    if (result != 'n') { // Check if there's a winner or tie
        return scores[result];
    }

    if(ismaximising){
        int bestscore = INT32_MIN;

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i][j] == 0){
                    grid[i][j]=ai;
                    int score = minimax(grid,depth+1,false);
                    grid[i][j]=0;
                    bestscore=max(score,bestscore);
                }
            }
        }
        return bestscore;
    }
    else{
        int bestscore=INT32_MAX;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i][j] == 0){
                    grid[i][j]=human;
                    int score = minimax(grid,depth+1,true);
                    grid[i][j]=0;
                    bestscore=min(score,bestscore);
                }
            }
        }
        return bestscore;
    }
}

void Bestmove(){

    int bestscore=INT32_MIN;
    int movex,movey;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(grid[i][j]== 0){
                grid[i][j]=ai;
                int score = minimax(grid,0,false);
                grid[i][j]=0;
                if(score>bestscore){
                    bestscore=score;
                    movex=i;
                    movey=j;
                }
            }
        }

    }
    grid[movex][movey]=ai;
    humanplaying=true;


}
