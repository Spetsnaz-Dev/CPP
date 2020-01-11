// #include<bits/stdc++.h>
// #define ll unsigned long long int
// using namespace std;

// int main() 
// {
//     ll n;
//     cin>>n;
//     unordered_map<ll, ll> mp;

//     while(n--){
//         ll l,r;
//         cin>>l>>r;
//         for(ll i=l;i<=r;i++){
//             mp[i]++;
//             //cout<<mp[i]<<" ";
//         }
//     }
//     ll x,y;
//     cin>>x>>y;
//     ll houseCount = 0;
//     for(auto i : mp){
//         if(i.second >= x && i.second <= y)
//             houseCount++;
//     }
//     cout<<houseCount<<endl;

//     return 0;
// }
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
 
#define CASES int t;cin>>t;while(t--)
#define REP(i, val, b) for (int i = val; i < b; ++i)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
 
int main() {
	fastio
	int n;
	cin >> n;
	long long l, r, x, y;
	map<long long, long long> M;
	REP(i,0,n) {
		cin >> l >> r;
		M[l]++;
		M[r+1]--;
	}
	cin >> x >> y;
	long long ans = 0, ct = 0;
	map<long long, long long>::iterator it = M.begin(), prev = M.begin();
	++it;
	ans += prev->second;
	for (; it != M.end(); ++it) {
		if (ans >= x && ans <= y) ct += it->first - prev->first;
		// ans -= prev->second;
		ans += it->second;
		prev = it;
	}
	cout << ct;
	return 0;
}