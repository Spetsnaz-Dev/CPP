// Min Cost Path
// Method 1
int minPathSum(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,0));
    dp[0][0] = grid[0][0];
    for(int i=1;i<m;i++)
        dp[i][0] = dp[i-1][0] + grid[i][0];
    for(int j=1;j<n;j++)
        dp[0][j] = dp[0][j-1] + grid[0][j];
     for(int i=1;i<m;i++)
         for(int j=1;j<n;j++)
             dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
        return dp[m-1][n-1];
    }

// Method 2
int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        int i, j;
        vector<vector<int>> dp(n,vector<int>(m,0));
        dp[0][0] = grid[0][0];
        
        for(i=0; i<n; i++){
            for(j=0; i<m; j++){
                if(i>0 and j>0)
                    grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
                else if(i==0 and j>0)
                    grid[i][j] += grid[i][j-1];
                else if(i>0 and j==0)
                    grid[i][j] += grid[i-1][j];
            }
        }
        return grid[n-1][m-1];
    }
    