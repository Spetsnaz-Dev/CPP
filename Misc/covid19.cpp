#include "bits/stdc++.h"
#define base9 1e9
#define base7 1e7
#define ll long long int
using namespace std;
int n,t;
// solver function
void solve(vector<int> arr){
    int max_span = 0, min_span = INT_MAX, curr_span = 0;
    for (size_t i = 0; i < arr.size()-1; i++)
    {
        int diff = arr[i+1] - arr[i];
        if(diff <= 2){
            curr_span += 1;
            max_span = max(curr_span, max_span);
            // min_span = min(max_span, curr_span);
        }
        else {
            curr_span = 0;
        }
    }

    curr_span = 0;
    for (size_t i = 0; i < arr.size()-1; i++)
    {
        int diff = arr[i+1] - arr[i];
        
        if(diff <= 2){
            curr_span++;
        }
        else{
            min_span = min(curr_span, min_span);
            curr_span = 0;
        }
    }
    min_span = min(curr_span, min_span);

    cout<<min_span+1<<" "<<max_span+1;
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
        vector<int> v(n);
        for (size_t i = 0; i < n; i++)
            cin>>v[i];

        // Output
        solve(v);

        cout<<"\n";
    }
    return 0;
}
