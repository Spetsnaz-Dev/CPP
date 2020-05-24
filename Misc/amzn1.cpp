#include "bits/stdc++.h"
#define base9 1e9
#define base7 1e7
#define ll long long int
using namespace std;

static int speedUp = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
// solver functionzz
int solve(int n, int v[]){
    sort(v, v+n);

    int diff = INT_MAX;
    for(int i=1; i<n; i++){
        int currDiff = v[i] - v[i-1];
        diff = min(currDiff, diff);
    }
    return diff;
}

int main()
{  
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

        ll n; cin>>n;
        int v[n];
        for(int i=0; i<n; i++)
            cin>>v[i];

        // Output
        cout<<solve(n, v);

        cout<<"\n";
    return 0;
}
