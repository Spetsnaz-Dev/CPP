#include "bits/stdc++.h"
#define pb push_back
using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

// solver functionzz
vector<vector<char>> solve(vector<vector<char>> &board)
{
    int r = board.size(), c = board[0].size();
    
    // move right
    for(int i=0; i<r; i++){
        for(int j=c-1; j>=0; j--){
            if(board[i][j] == '#'){
                board[i][j] = '.';
                int x = j;
                while(x+1 < c and board[i][x+1] == '.')
                    x++;
                board[i][x] = '#';
            }
        }
    }

    // move down
    for(int j=c-1; j>=0; j--){
        for(int i=r-1; i>=0; i--){
            if(board[i][j] == '#'){
                board[i][j] = '.';
                int x = i;
                while(x+1 < r and board[x+1][j] == '.')
                    x++;
                board[x][j] = '#';
            }
        }
    }

    // print final state
    return board;
}

int main()
{   
    int r, c;
    cin>>r>>c;
    
    vector<vector<char>> v(r, vector<char> (c));
    for (int i = 0; i < r; i++){
        for(int j=0; j<c; j++){
            cin>>v[i][j];
        }
    }

    // Output
    auto board = solve(v);
    for(auto i : board){
        for(char ele : i){
            cout<<ele<<", ";
        }
        cout<<"\n";
    }
}
