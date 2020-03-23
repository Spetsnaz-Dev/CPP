#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int capacity[n], water[n];
    int i;
    for(i = 0; i < n; i++)
        cin>>capacity[i];
    
    int total = 0;
    for(i = 0; i < n; i++){
        cin>>water[i];
        total += water[i];
    }

    vector<pair<int, int>> v;
    for(i = 0; i < n; i++)
        v.push_back(make_pair(water[i], capacity[i]));
    
    sort(v.begin(), v.end(), greater<pair<int, int>>());

    int curr_total = 0, count = 0;
    for(i = 0; i < n; i++){
        if(curr_total < total){
            count++;
            curr_total += v[i].second;
        }
        else{
            cout<<count<<"\n";
            break;
        }
    }
    return 0;    
}