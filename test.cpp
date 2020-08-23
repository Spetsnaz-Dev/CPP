#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

unsigned long recur(int n, int sum, vector<vector<long>>& dp){
    if(n == 0)
        return sum == 0;
    
    if(sum == 0)
        return 1;
    
    if(dp[n][sum] != -1)
        return dp[n][sum] % mod;
        
    unsigned int res = 0;
    for(int i=0; i<=9; i++){
        if(sum - i >= 0)
            res = (res + recur(n-1, sum-i, dp) % mod) % mod;
    }
    return dp[n][sum] = res % mod;
}
int solve(int n, int target) {
    vector<vector<long>> dp(n+1, vector<long> (target+1, -1));
    long count = 0;
    
    for(int i=1; i<=9; i++){
        if(target - i >= 0)
            count = (count + (recur(n-1, target-i, dp) % mod) % mod);
    }
    return count % mod;
}
int main(){
    int n,k;
    cin>>n>>k;
    cout<<solve(n, k)<<endl;

    return 0;
}