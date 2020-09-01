#include "bits/stdc++.h"
#define base9 1e9
#define base7 1e7
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
// ll solve(ll a, ll b, ll l, ll r)
// {
//     ll count = 0, sum = 0;
//     while (1)
//     {
//         sum += a;
//         if(sum <= r and sum >= l)
//             count++;
//         else
//             return count;
        
//         sum += b;
//         if(sum <= r and sum >= l)
//             count++;
//         else
//             return count;
//     }
//     return count;
// }

int main()
{ 
    // Input
    ll t,a,b,l,r;
    cin>>t;
    while (t--){
        cin>>a>>b>>l>>r;

        if(r < a){
            cout<<0<<"\n";
            continue;
        }

        // Output
        bool end = 0;
        ll count = 0, sum = 0;
        while(sum < l){
            sum += a;
            end = 0;
            if(sum < l){
                sum += b;
                end = 1;
            }
            if(sum >= l){
                count++;
                break;
            }
        }

        while (sum < r)
        {
            if(end == 1){
            sum += a;
            if(sum <= r and sum >= l)
                count++;
            
            sum += b;
            if(sum <= r and sum >= l)
                count++;
            }
            else
            {
                sum += b;
            if(sum <= r and sum >= l)
                count++;
            
            sum += a;
            if(sum <= r and sum >= l)
                count++;
            }
        }
        cout<<count<<"\n";
    }
    return 0;
}
