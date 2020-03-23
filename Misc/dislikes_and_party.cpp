// https://www.hackerearth.com/challenges/competitive/march-circuits-20/algorithm/dislikes-and-party-567b9605/
#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;
int main()
{
    ll n;
    cin>>n;
    ll arr[10][10];
    ll i,j;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            cin>>arr[i][j];
        }
    }
    set<pair<ll, ll>> s;
    ll likeShakes = 0;
    for(i=0;i<10;i++){
        ll curr = arr[i][0];
        for(j=1;j<10;j++){
            pair<ll, ll> p1 = make_pair(curr, arr[i][j]);
            pair<ll, ll> p2 = make_pair(arr[i][j], curr);
            if(curr < arr[i][j]){
                if(s.find(p1) == s.end())
                    ++likeShakes;
                s.insert(p1);
            }
            else{
                if(s.find(p2) == s.end())
                    ++likeShakes;
                s.insert(p2);
            }
        }
    }
    ll totalShakes = n*(n-1)/2;

    cout<<totalShakes - likeShakes<<"\n";
    return 0;
}