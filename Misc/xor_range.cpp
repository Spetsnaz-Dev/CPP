// XOR of a given range between L and R inclusive
#include <bits/stdc++.h>
using namespace std;
 const int N=100005;
 const int inf=1e18;
 const double eps=1e-9;

int xorf(int x){
    int z=x%4;
    if(z==0){
        return (x^0);
    }
    if(z==1){
        return (1^0);
    }
    if(z==2){
    return ((x+1)^0);
    }
    if(z==3){
        return (0^0);
    }
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	int t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        cout<<(xorf(r)^(xorf(l)^l))<<endl;
    }	
return 0;
}