#include <bits/stdc++.h> 
using namespace std;

int main() 
{
    int n,d;
    cin>>n>>d;
    vector<int> v(n);
    for(int i=1; i<=n; i++)
        cin>>v[i];
    sort(v.begin(), v.end());

    int res = 0;
    for(int i=0; i+1<n; i++){
        if(v[i+1]-v[i] <= d){
            res++;
            i++;
        }
    }
    cout<<res<<endl;
} 