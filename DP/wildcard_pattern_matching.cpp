int wildCard(string patt,string str)
{
    int n = str.size(), k = patt.size();
    
    vector<vector<int>> dp(k+1, vector<int>(n+1, 0));
    dp[0][0] = 1;
    for(int i=1; i<=k; i++)
        if(patt[i-1] == '*') 
            dp[i][0] = dp[i-1][0];

    for(int i=1; i<=k; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(patt[i-1] == str[j-1] or patt[i-1] == '?')
                dp[i][j] = dp[i-1][j-1];
                
            else if(patt[i-1] == '*')
                dp[i][j] = dp[i-1][j] or dp[i][j-1];

            else if(patt[i-1] != str[j-1])
                dp[i][j] = 0;
        }
    }
    return dp[k][n];
}