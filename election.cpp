#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

string solve(string s, int n){
    vector<pair<ll,ll>> arr(n, {LONG_LONG_MAX, LONG_LONG_MAX});
    for(ll i = 0; i < n; i++)
    {
        if(s[i]=='B'){
            ll j=i+1, t=0;

            if(j < n){
                for(j;j<n;j++){
                    if(s[j] == '-')
                        arr[j].second = min(arr[j].second,t);
                    else if(s[j] == 'B'|| s[j] == 'A')
                        break;
                    t++;
                }
            }
        }
        else if(s[i]=='A'){
            ll t=0;
            ll j=i-1;
            if(j>=0)
            {
                for(j;j>=0;j--)
                {
                    if(s[j]=='-')
                    {
                        arr[j].first=min(arr[j].first,t);
                    }
                    else if(s[j]=='A'||s[j]=='B')
                    {
                        break;
                    }
                    t++;
                }
            }
        }
    }

    ll count_a = 0, count_b = 0;
    for(ll i=0;i<n;i++)
    {
        ll x = arr[i].first, y = arr[i].second;;
        
        if(s[i]=='A')
            count_a++;
        else if(s[i]=='B')
            count_b++;

        if(s[i] == '-'){
            if(x > y)
                count_b++;
            else if(x < y)
                count_a++;
        }
    }
    if(count_a > count_b)
        return "A";
    else if(count_b > count_a)
        return "B";
    return "Coalition government";
}
int main() {
    ll n;
    string s;
    // take size
    cin>>n;
    // take string
    cin>>s;

    cout<<solve(s, n)<<"\n";

    return 0;
}