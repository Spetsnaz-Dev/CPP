#include "bits/stdc++.h"
using namespace std;

int main()
{
    int t;cin>>t;
    while (t--)
    {
        long a, b;
        cin>>a>>b;

        if(a == 1 and b == 1){
            cout<<"1\n";
        }
        else{
            long even_a, even_b, odd_a, odd_b;
            
            even_a = a/2;
            even_b = b/2;

            odd_a = a - even_a;
            odd_b = b - even_b;

            // cout<<odd_a<<" - "<<odd_b<<"\n";
            // cout<<even_a<<" - "<<even_b<<"\n";
            
            long long res = (even_a * even_b) + (odd_a * odd_b);
            cout<<res<<"\n";
        }
    }
}