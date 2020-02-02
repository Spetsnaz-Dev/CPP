#include<bits/stdc++.h>
using namespace std;
int min(int x, int y)
{
    if(x > y)
        return y;
    else return x;
}
int findOperations(string str1, string str2, int m, int n)
{
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
        for(int j=0;j<=n;j++) {
            if(i == 0)
                dp[i][j] = j;

            else if(j == 0)
                dp[i][j] = i;
            
            else if(str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]);
        }
    return dp[m][n];
}
int main()
 {
	int t;
    cin>>t;
    while(t--) {
        int m,n;
        cin>>m>>n;
        string s1, s2;
        cin>>s1;
        cin>>s2;
        cout<<findOperations(s1, s2, m, n)<<"\n";
        }
	return 0;
}