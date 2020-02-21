// No of hops to reach end using 0, 1 & 2
#include<iostream>
using namespace std;
int main()
 {
	int t;
    cin>>t;
    while(t--) {
        int dist;
        cin>>dist;
        int dp[dist+1] = {0};
        dp[0] = 1;  dp[1] = 1;    dp[2] = 2;
        for(int i=3;i<=dist;i++)
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];

        cout<<dp[dist]<<"\n";
        }
	return 0;
}