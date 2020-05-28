#include<bits/stdc++.h>
using namespace std;
// int solve(string s)
// {
//     int n = s.size();

//     if(n  <= 1)
//         return 0;

//     vector<vector<int>> dp(n, vector<int>(n, 0));
//     for(int gap = 1; gap < n; gap++) //min gap between low and high is 1
//     {
//         int i = 0, j = gap;
//         while(j < n)
//         {
//             dp[i][j] = s[i] == s[j] ? dp[i+1][j-1] : (min(dp[i+1][j], dp[i][j-1]) + 1);
//             ++j;
//             ++i;
//         }
//     }
//     return dp[0][n-1];
// }
int lps(string a, string b)
{
    int n = a.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for (size_t i = 0; i < n+1; i++)
    {
        for (size_t j = 0; j < n+1; j++)
        {
            if(i == 0 or j == 0)
                dp[i][j] = 0;
            else if(a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[n][n];
}
int solve(string s)
{
    string rev = s;
    reverse(rev.begin(), rev.end());
    int len = lps(s, rev);

    return s.size() - len;
}
int main()
 {
	int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;

        cout<<solve(s)<<"\n";
        }
	return 0;
}