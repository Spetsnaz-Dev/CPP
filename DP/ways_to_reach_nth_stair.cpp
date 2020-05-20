// No of ways to reach nth stair
#define mod 1000000007
long long countWays(int m){
    vector<int> dp(m+1);
    dp[0] = 1, dp[1] = 1;
    
    for(int i=2; i<=m; i++)
        dp[i] = (dp[i-1] + dp[i-2]) % mod;
        
    return dp[m];
}