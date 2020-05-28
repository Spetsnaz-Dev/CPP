#include "bits/stdc++.h"
#define base9 1e9
#define base7 1e7
#define mod 1000000007
#define ll long long int
using namespace std;

static int speedUp = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
// solver functionzz
long solve(int faces, int throws, int sum)
{
    if(sum == 0 and throws == 0)
        return 1;
    if(sum < 0 or throws == 0)
        return 0;
    
    //for check if already calculated
    vector<vector<int>> dp(throws+1, vector<int> (sum+1, -1));

    if (dp[throws][sum] != -1) 
        return dp[throws][sum]; 

    int res = 0;
    for(int i=1; i<=faces; i++)
    {
        res =  (res + solve(faces, throws-1, sum- i) % mod) % mod;
    }
    dp[throws][sum] = res;
    return res;
}

int main()
{  
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Input
    int faces, throws, sum; cin>>faces>>throws>>sum;

    // Output
    cout<<solve(faces, throws, sum);

    cout<<"\n";

    // return 0;
}
