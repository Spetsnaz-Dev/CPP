int maximizeTheCuts(int n, int x, int y, int z)
{
    vector<int> dp(n+1);
    vector<int> v;
    v = {x, y, z};
    sort(v.begin(), v.end());
    
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(i == v[j])
                dp[i] = max(1, dp[i]);
    
            else if(i > v[j] and dp[i - v[j]] > 0)
                dp[i] = max(dp[i - v[j]] + 1, dp[i]);
        }
    }
    return dp[n];
}