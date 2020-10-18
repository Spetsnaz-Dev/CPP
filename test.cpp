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


// solver functionzz
int solve(vector<int>& arr, int n){
    int count = 0, res = 0;
    for(int i=0; i<n; i++){
        count = 1;
        int curr = arr[i];
        while(i+1 < n and arr[i] == arr[i+1] and arr[i] % 2 != 0){
            i++;
            count++;
        }
        if(curr & 1)
            res = max(res, count);
    }
    return res;
}

int main()
{
    // Input
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    
    // Output
    cout<<solve(v, n);
    cout<<"\n";
    return 0;
}
