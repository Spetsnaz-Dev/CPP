#include<bits/stdc++.h>
using namespace std;
int t,n,m;
int main()
{
    cin>>t;
    while(t--)
    {
        // input
        cin>>n>>m;
        int type[n], fruits[n];
        for(int i = 0; i < n; i++)
            cin>>type[i];
        for(int i = 0; i < n; i++)
            cin>>fruits[i];
        
        //output
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++)
            mp[type[i]] += fruits[i];
        int min = INT_MAX;
        for(auto i : mp){
            if(i.second < min)
                min = i.second;
        }
        cout<<min<<"\n";
    }
    return 0;
}