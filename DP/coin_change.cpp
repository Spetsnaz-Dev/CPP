// #include<bits/stdc++.h>
// using namespace std;
// // Given a value N, find the number of ways to make change for N cents,
// // if we have infinite supply of each of S = { S1, S2, .. , Sm}
// // valued coins. 
// int coinChange(int arr[], int total, int n)
// {
//     int dp[total+1];
//     memset(dp, 0, sizeof(dp));
//     dp[0] = 1;
//     for (int i = 0; i < n; i++)
//         for(int j = 1; j <= total; j++){
//             if(j >= arr[i])
//                 dp[j] += dp[j - arr[i]];
//         }
//     return dp[total];
// }
// int main()
//  {
// 	int t;
//     cin>>t;
//     while(t--) {
//         int n;
//         cin>>n;
//         int arr[n];
//         for(int i=0;i<n;i++)
//             cin>>arr[i];
//         int m;
//         cin>>m;
//         cout<<coinChange(arr, m, n)<<"\n";
//         }
// 	return 0;
// }
#include<bits/stdc++.h>
using namespace std;
int coinChange(int coins[], int total, int size)
{
    int dp[size+1][total+1];
    memset(dp, 0, sizeof(dp));
    for(int i=0;i<=size;i++)
        dp[i][0] = 1;
    
    for(int i=1;i<=size;i++){
        for(int j=1;j<=total;j++){
            if(coins[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
        }
    }
    return dp[size][total];
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
