#include<iostream>
using namespace std;

int t, r, c;
void printSolution(){}
bool isSafe(int x, int y, int sol[8][8]){
    return (x < 8 && y < 8) && 
            (x >=0 && y >= 0) && 
            (sol[x][y] == 0 || sol[x][y] == -1); 
}
int solveBishopUtil(int x, int y, int move_i, int sol[8][8], int xMove[], int yMove[], int count)
{
    int k, next_x, next_y;
    if(move_i == 64 || count == 32)
        return count;
    
    for(k = 0; k < 4; k++){
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if(isSafe(next_x, next_y, sol)){
            sol[next_x][next_y] = -1;
            if(solveBishopUtil(next_x, next_y, move_i+1, sol, xMove, yMove, count+1) == 1)
                return 1;
            else
                sol[next_x][next_y] = -1;
        }
    }
    return 0;
}
void solveBishop(int r, int c)
{
    int sol[8][8] = { { 0, 1, 0, 1, 0, 1, 0, 1 }, 
                       { 1, 0, 1, 0, 1, 0, 1, 0 }, 
                       { 0, 1, 0, 1, 0, 1, 0, 1 }, 
                       { 1, 0, 1, 0, 1, 0, 1, 0 },
                       { 0, 1, 0, 1, 0, 1, 0, 1 },
                       { 1, 0, 1, 0, 1, 0, 1, 0 },
                       { 0, 1, 0, 1, 0, 1, 0, 1 },
                       { 1, 0, 1, 0, 1, 0, 1, 0 }, }; 
    
    int xMove[4] = { 1, 1, -1, -1 };
    int yMove[4] = { 1, -1, 1, -1 };

    int count = 0;
    sol[r][c] = -1;
    cout<<solveBishopUtil(r, c, 1, sol, xMove, yMove, count)<<"\n";
}
int main()
{   
    // 0 is black and 1 is white
    //int board[8][8]= { { 0, 1, 0, 1, 0, 1, 0, 1 }, 
    //                    { 1, 0, 1, 0, 1, 0, 1, 0 }, 
    //                    { 0, 1, 0, 1, 0, 1, 0, 1 }, 
    //                    { 1, 0, 1, 0, 1, 0, 1, 0 },
    //                    { 0, 1, 0, 1, 0, 1, 0, 1 },
    //                    { 1, 0, 1, 0, 1, 0, 1, 0 },
    //                    { 0, 1, 0, 1, 0, 1, 0, 1 },
    //                    { 1, 0, 1, 0, 1, 0, 1, 0 }, }; 
    cin>>t;
    while(t--)
    {   // 1 <= r,c <= 8
        cin>>r>>c;
        solveBishop(r-1, c-1);
    }
    return 0;
}