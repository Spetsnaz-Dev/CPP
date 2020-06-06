#include "bits/stdc++.h"
#define base9 1e9
#define base7 1e7
#define ll long long int
using namespace std;
int t, n;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

// solver functionzz
void solve(int n)
{
    unordered_map<int, int> mp;
    for(int i=1; i<=n*n; i++)
        mp[i] = i;
    
    ll x = 1, i = 0, j = n-1;
    // int arr[n][n] = {{0}};
    vector<vector<int>> arr(n, vector<int> (n));

    while (i < n)
    {
        arr[i][i] = x;
        mp.erase(x);
        x += 2;
        i += 1;
    }
    i = 0, x = 2;
    while(i < n and j >= 0)
    {
        arr[i][j] = x;
        mp.erase(x);
        x += 2;
        i += 1;
        j -= 1;
    }
    auto it = mp.begin();
    for (int i = 0; i < n; i++)
        for(int j=0; j < n; j++)
            if(arr[i][j] == 0){
                arr[i][j] = it->first;
                mp.erase(it->first);
                it++;
            }
    
    for (int i = 0; i < n; i++){
        for(int j=0; j < n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main()
{  
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Input
    cin>>t;
    while (t--){
        cin>>n;

        // Output
        solve(n);

        cout<<"\n";
    }
    return 0;
}
