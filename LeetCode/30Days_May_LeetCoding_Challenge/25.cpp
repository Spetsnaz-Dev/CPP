static int speedUp = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int maxUncrossedLines(vector<int>& arr, vector<int>& brr) {
        int n = arr.size(), m = brr.size();
        
        vector<vector<int>> dp(n+1, vector<int> (m+1));
        
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(arr[i-1] == brr[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};