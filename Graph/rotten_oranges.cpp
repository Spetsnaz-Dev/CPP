#include "bits/stdc++.h"
using namespace std;

// Method 2
bool isSafe(int x, int y, int n, int m){return (x>=0 and y>=0 and x<n and y<m) ;}

// Function to check whether there is still a fresh 
// orange remaining 
bool checkall(vector<vector<int>>& grid) 
{ 
	for (int i=0; i<grid.size(); i++) 
	for (int j=0; j<grid[i].size(); j++) 
		if (grid[i][j] == 1) 
			return true; 
	return false; 
} 

bool isDelimeter(pair<int, int> temp) { return (temp.first == -1 && temp.second == -1); } 

int rottenOranges(vector<vector<int>>& grid) {

    queue<pair<int, int>> q;
    for(int i=0; i<grid.size(); i++)
        for(int j=0; j<grid[i].size(); j++)
            if(grid[i][j] == 2)
                q.push(make_pair(i, j));

    if(q.empty())
        return -1;

    int n = grid.size(), m = grid[0].size(), ans = 0;
    // Delimemter
    q.push(make_pair(-1, -1));

    while(!q.empty()) {
        bool flag = false;  //indicator for delimeter

        while (!isDelimeter(q.front())) {
            pair<int, int> p = q.front();
            int i = p.first;
            int j = p.second;
            //check bottom adjacent cell
            if(isSafe(i+1, j, n, m) and grid[i+1][j] == 1){
                if(!flag) ans++, flag = true;

                grid[i+1][j] = 2;
                i++;
                q.push(make_pair(i, j));
                i--;
            }
            //check left adj cell
            if(isSafe(i, j-1, n, m) and grid[i][j-1] == 1){
                if(!flag) ans++, flag = true;

                grid[i][j-1] = 2;
                j--;
                q.push(make_pair(i, j));
                j++;
            }
            //check top adj cell
            if(isSafe(i-1, j, n, m) and grid[i-1][j] == 1){
                if(!flag) ans++, flag = true;

                grid[i-1][j] = 2;
                i--;    
                q.push(make_pair(i, j));
                i++;
            }
            //check right adj cell
            if(isSafe(i, j+1, n, m) and grid[i][j+1] == 1){
                if(!flag) ans++, flag = true;

                grid[i][j+1] = 2;
                j++;
                q.push(make_pair(i, j));
                j--;
            }
            q.pop();
        }
        q.pop();

        if(!q.empty())
        { q.push({-1, -1}); }
    }
    return (checkall(grid))? -1: ans; 
}

// Method 2 DFS Implementation
int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;

        int counter{0};
        queue<pair<int,int>> q;
        
      for(auto row=0; row<grid.size(); row++)
      {
          for(auto col=0; col<grid[0].size(); col++)
          {
                if(grid[row][col]==2)
                {
                    q.push({row,col});
                }
                else if(grid[row][col]==1)
                {
                    ++counter;
                }
          }
      }
       if(!counter) return 0;

        int res{0};
        while(!q.empty())
        {  
               ++res;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto row=q.front().first;
                auto col=q.front().second;
                q.pop();

                if(row>0 && grid[row-1][col]==1)
                {
                    grid[row-1][col]=2;//mark is visisted
                    q.push({row-1,col});
                    --counter;
                }
                if(row<grid.size()-1 && grid[row+1][col]==1)
                {
                    grid[row+1][col]=2;//mark is visisted
                    q.push({row+1,col});
                    --counter;
                }
                if(col>0 && grid[row][col-1]==1)
                {
                    grid[row][col-1]=2;//mark is visisted
                    q.push({row,col-1});
                    --counter;
                } 
                if(col<grid[0].size()-1 && grid[row][col+1]==1)
                {
                    grid[row][col+1]=2;//mark is visisted
                    q.push({row,col+1});
                    --counter;
                }
            }
        }
            if(!counter)
            {
                return res-1;
            }
            return -1;
}
int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> grid(n);

    int ele;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>ele;
            grid[i].push_back(ele);
        }
    }

    cout<<rottenOranges(grid)<<"\n";

    return 0;
}
