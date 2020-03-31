#include<iostream>
#include<climits>
using namespace std;
int cutRod(int arr[], int size)
{
    int dp[size+1] = {0};
    dp[0] = 0;

    for(int i=1;i<=size;i++){
        int val = INT_MIN;
        for(int j=0;j<i;j++)
            val = max(val, arr[j] + dp[i-j-1]);
        dp[i] = val;
    }
    return dp[size];
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
        cout<<cutRod(arr, n)<<"\n";
        }
	return 0;
}