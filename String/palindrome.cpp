#include<bits/stdc++.h>
using namespace std;

int main()
 {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        char str[n];
        for(int i=0;i<n;i++)
            cin>>str[i];
        
        int low= 0, high= n-1;
        bool flag= 1;
        while(low <= high) {
            if(str[low++] != str[high--])
                { flag=0; break; }
        }
        if(flag == 1)
            cout<<"Yes"<<"\n";
        else cout<<"No"<<"\n";
    }
	return 0;
}