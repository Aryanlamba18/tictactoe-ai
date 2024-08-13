#include"grid.h"
#include"minimax.h"
#include<iostream>

using namespace std;

int main(){
    
    int moves=1;
    Bestmove();
    printgrid(grid);
    
    while(moves<9){
        if(humanplaying){
        int x,y;

        do
        {   cout<<"enter pos for p1"<<endl;
            
            cin>> x >> y ;

            if(x<1 || x>3 || y<1 || y>3 || grid[x-1][y-1]!=0){
                cout<<"invalid move try again"<<endl;
            }

        } 
        while (x<1 || x>3 || y<1 || y>3 || grid[x-1][y-1]!=0);
        grid[x-1][y-1]= human;
        moves++;
        cout<<moves<<endl;
        

        if(moves == 9){
            cout<<"tie";
            break;
        }

        
        
        if(win(grid)){
            cout<<"p1 won"<<endl;
            break;
        }
        humanplaying=false;
    } 
        else{
            Bestmove();
            moves++;
            printgrid(grid);


        
        if(moves == 9){
            cout<<"tie";
            break;
        }
        
        if(win(grid)){
            cout<<"p2 won"<<endl;
            break;
        }
        humanplaying=true;
        }
        
    }

    
}


