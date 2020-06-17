#include "bits/stdc++.h"
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,0));
    dp[0][0] = grid[0][0];
    for(int i=1;i<m;i++)
        dp[i][0] = dp[i-1][0]/2 + grid[i][0];
    for(int j=1;j<n;j++)
        dp[0][j] = dp[0][j-1]/2 + grid[0][j];
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
                dp[i][j] = min(dp[i-1][j],dp[i][j-1])/2 + grid[i][j];
    return dp[m-1][n-1];
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> arr(n, vector<int> (n));
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<minPathSum(arr)<<"\n";
}