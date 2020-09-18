#include "bits/stdc++.h"
#define ll long long int
#define ull unsigned long long int
#define pb push_back

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

vector<int> a;
vector<vector<int>> dp;
int n;
int ok(int i, int turn){
    if(i>=n)
        return dp[i][turn]=0;
    if(dp[i][turn]!=-1)
        return dp[i][turn];
    if(turn){
        int mini=1e9;
        if(i<n && a[i]==1)
            mini=min(mini,ok(i+1,turn^1)+1);
        if(i<n && a[i]==0)
            mini=min(mini,ok(i+1,turn^1));
        if(i+1<n && a[i]==0 && a[i+1]==1)
            mini=min(mini,ok(i+2,turn^1)+1);
        if(i+1<n && a[i]==0 && a[i+1]==0)
            mini=min(mini,ok(i+2,turn^1));
        if(i+1<n && a[i]==1 && a[i+1]==0)
            mini=min(mini,ok(i+2,turn^1)+1);
        if(i+1<n && a[i]==1 && a[i+1]==1)
            mini=min(ok(i+1, turn^1) + 1,ok(i+2,turn^1) + 2);
        return dp[i][turn]=mini;
    }
    else{
        int mini=1e9;
        mini=min(ok(i+1,turn^1),ok(i+2,turn^1));
        return dp[i][turn]=mini;
    }
}

int main()
{
    ll t;
    cin>>t;
    while (t--){
        cin>>n;
        dp.resize(n, vector<int>(2, -1));
        a.resize(n);
        for(int i=0; i<n; i++)
            cin>>a[i];

        cout<<ok(0, 1);
        cout<<"\n";
    }
    return 0;
}