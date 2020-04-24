#include<bits/stdc++.h>
using namespace std;
void subsetSumPossible(int arr[], int n, int sum)
{
    if(sum % 2 != 0){
        cout<<"NO\n";
        return;
    }
    
    sum = sum / 2;
    bool dp[n+1][sum+1] = {{0}};
    for (size_t i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (size_t i = 1; i <= sum; i++)
        dp[0][i] = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(dp[i-1][j])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
        }
    }
    if(dp[n][sum])
        cout<<"YES\n";
    else
        cout<<"NO\n";
}
int main()
 {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int arr[n], sum = 0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            sum += arr[i];
        }
        subsetSumPossible(arr, n, sum);
        }
	return 0;
}