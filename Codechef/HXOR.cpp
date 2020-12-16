#include "bits/stdc++.h"
#define ll long long int
#define ull unsigned long long int
#define pb push_back
using namespace std;

// print ans
void printAns(vector<ll> arr){
    for(ll i=0; i<arr.size(); i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
}
// Krantiveer
int main()
{
    ll t, n, x, z;
    cin>>t;
    while (t--)
    {
        cin>>n>>x;    

        // array input
        vector<ll> arr(n);
        for(ll i=0; i<n; i++)
            cin>>arr[i];
        
        ll i=0;
        for(ll k=x; k>0 and i<n-1; k--)
        {
            bool flag = 0;
            ll p = log2(arr[i]);
            ll r = pow(2, p);
            arr[i] = arr[i] ^ r;
            for (ll j = i+1; j<n; j++){
                if((arr[j]^r) < arr[j]){
                    arr[j] = arr[j] ^ r;
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                arr[n-1] = arr[n-1] ^ r;
            }

            while (arr[i] <= 0)
                i++;
            
            z = k+1;
            if(n<3 and z%2 == 0 and z > 0){
                arr[n-1] = arr[n-1] ^ 1;
                arr[n-2] = arr[n-2] ^ 1;
            }
        }
        printAns(arr);
    }
}