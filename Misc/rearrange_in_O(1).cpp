#include "bits/stdc++.h"
#define base9 1e9
#define base7 1e7
#define ll long long int
using namespace std;

// solver functionzz
void solve(int arr[], int n){
    for(int i=0; i<n; i++)
    {
        arr[i] += (arr[arr[i]]%n) * n;
        // cout<<arr[i]/n<<" ";
    }
    for(int i=0; i<n; i++)
        arr[i] = arr[i] / n;

    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}

int main()
{  
    // Fast I/O
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    // Input
    int t;
    cin>>t;
    while (t--){
        ll n; cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        // Output
        solve(arr, n);

        cout<<"\n";
    }
    return 0;
}
