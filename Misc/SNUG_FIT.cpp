#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll n,t; //Declared here to remove SIGEMT
int main()
 {
	//ll t;
    cin>>t;
    while(t--) {
        //ll n;
        cin>>n;
        ll arr[n], brr[n];
        //Input
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        for(ll i=0;i<n;i++)
            cin>>brr[i];
        
        // Sort and get output
        sort(arr, arr+n);
        sort(brr, brr+n);
        ll s = 0;
        for(ll i=0;i<n;i++)
            s += min(arr[i], brr[i]);
        cout<<s<<endl;
    }
	return 0;
}