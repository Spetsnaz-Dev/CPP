// Nuts AND bOLTS Problem
#include<bits/stdc++.h>
using namespace std;

int main()
{  
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Input
    int t;
    cin>>t;
    while (t--){
        int n; cin>>n;
        char c;
        map<char,int> mp;
	    char arr1,arr2;
	    for(int i=0;i<n;i++)
	    {
	       cin>>arr1;
	       mp[arr1]++;
	    }
	    for(int i=0;i<n;i++)
	    {
	       cin>>arr2;
	       mp[arr2]++;
	    }
        string res="";
	    for(auto x:mp)
	    {
	        if(x.second >= 2)
	        {
	            res+=x.first;
	            res += " ";
	        }
	   }
	   cout<<res<<"\n"<<res<<"\n";
	}
    return 0;
}
