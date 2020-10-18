#include "bits/stdc++.h"
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    return a<b;
}
long solve(vector<pair<int, int>>& arr, int n){
    sort(arr.begin(), arr.end(), compare);
}
int main()
{
    int n;
    cin>>n;
    vector<int> plots(n), pu(n);
    for(int i=0; i<n; i++)
        cin>>plots[i];
    for(int i=0; i<n; i++)
        cin>>pu[i];
    
    vector<pair<int, int>> vp;
    for (int i = 0; i < n; i++)
        vp.push_back({plots[i], pu[i]});

    cout<<solve(vp, n)<<"\n";

    return 0;
}