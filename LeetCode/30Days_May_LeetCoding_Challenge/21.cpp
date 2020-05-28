class Solution {
public:
    int countSquares(vector<vector<int>>& arr) {
        int n = arr.size(), m = arr[0].size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        
        int res = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++)
            {   
                if(arr[i-1][j-1] == 1)
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
                res += dp[i][j];
            }
        }
        return res;
    }
};