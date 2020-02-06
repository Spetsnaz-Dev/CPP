// Hackerrank
#include<bits/stdc++.h> 
using namespace std; 
typedef long long int ll; 
  
// function to find gcd of two integer numbers 
ll gcd(ll a, ll b) 
{ 
    if (!a) 
       return b; 
    return gcd(b%a,a); 
} 
int main()
{
    ll n;
    cin>>n;
    ll count = 0;
    
    for(int i=1;i<n;i++)
        if(gcd(i, n) == 1)
            count ++;
    
    cout<<count<<"\n";

    return 0;
}