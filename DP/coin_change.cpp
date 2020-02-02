#include<bits/stdc++.h>
using namespace std;
// Given a value N, find the number of ways to make change for N cents,
// if we have infinite supply of each of S = { S1, S2, .. , Sm}
// valued coins. 
int coinChange(int arr[], int total, int n)
{
    int dp[total+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < n; i++)
        for(int j = 1; j <= total; j++){
            if(j >= arr[i])
                dp[j] += dp[j - arr[i]];
        }
    return dp[total];
}
int main()
 {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int m;
        cin>>m;
        cout<<coinChange(arr, m, n)<<"\n";
        }
	return 0;
}