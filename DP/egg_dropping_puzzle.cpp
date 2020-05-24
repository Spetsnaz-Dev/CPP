// n = eggs, k = floors
int eggDrop(int n, int k) 
{
    vector<vector<int>> dp(k+1, vector<int> (n+1, 0));
    
    for (int i = 1; i <= n; i++)
        dp[1][i] = 1;
    for (int i = 1; i <= k; i++)
        dp[i][1] = i;
    for (int i = 2; i <= k; i++){
        for (int j = 2; j <= n; j++) {
            dp[i][j] = INT_MAX;
            for (int x = 1; x <= i; x++) {
                int eggBroken = dp[x - 1][j - 1];
                int eggSurvived = dp[i - x][j];
                int temp = max(eggBroken, eggSurvived) + 1;
                dp[i][j] = min(temp, dp[i][j]);
            }
        }
    }
 return dp[k][n];
}