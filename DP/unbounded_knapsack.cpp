#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {   // Input
        int n, w;
        cin>>n>>w;
        int val[n], weight[n];
        register int i;
        for(i = 0; i < n; i++)
            cin>>val[i];
        for(i = 0; i < n; i++)
            cin>>weight[i];
        
        int dp[n+1][w+1];
        for(i = 0; i <= n; i++)
            for(int j = 0; j <= w; j++){
                if(j == 0 || i == 0)
                    dp[i][j] = 0;
                else if(weight[i-1] <= j)
                    dp[i][j] = max(val[i-1] + dp[i][j - weight[i-1]], dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        cout<<dp[n][w]<<"\n";
    }
    return 0;
}