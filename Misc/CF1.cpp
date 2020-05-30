#include "bits/stdc++.h"
#define base9 1e9
#define base7 1e7
#define ll long long int
using namespace std;

int checkBaseCases(int n, int m)
{
    if(n == m and n == 1)
        return 1;
    int res = 0;
    if(n == 1 or m == 1)
    {
        int len = max(n, m);
        for(int j=1; j<=m; j+=2)
        res += 1;
        return res;
    }
    if(n == 2 or m == 2)
    {
        return max(m, n);
    }
    else
        return 0;
}
// solver functionzz
int solve(int n, int m)
{
    int res = 0;

    //base cases
    int t = checkBaseCases(n, m);
    if(t != 0)
        return t;
    
    if(n % 2 == 0)
        return (m*n/2);
    else
        res = m*(n-1)/2;

    for(int j=1; j<=m; j+=2)
        res += 1;

    return res;
}

int main()
{  
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Input
    int t;
    cin>>t;
    while (t--){
        int n, m; cin>>n>>m;

        // Output
        cout<<solve(n, m)<<"\n";
    }
    return 0;
}
