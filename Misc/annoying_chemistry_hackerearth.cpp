// https://www.hackerearth.com/challenges/competitive/march-circuits-20/algorithm/annoying-chemistry-f5fb9556/
#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;

int main()
{
    ll x, y, p, q;
    cin>>x>>y>>p>>q;
    
    ll base_c = x / __gcd(x, p);
    ll base_h = y / __gcd(y, q);
    ll base_rhs = __gcd(base_c, base_h);
    ll coeff = base_c * base_h / base_rhs;
    
    cout<<coeff*p/x<<" "<<coeff*q/y<<" "<<coeff<<"\n";
    return 0;
}