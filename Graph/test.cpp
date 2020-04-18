// Rotten Oranges
int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty())
        {
            return 0;
        }

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