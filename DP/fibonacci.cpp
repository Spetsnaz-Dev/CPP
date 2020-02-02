#include<iostream>
#define ll unsigned long long int
using namespace std;
int main()
 {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        ll arr[n+1];
        arr[0] = 0;
        arr[1] = 1;
        cout<<arr[1]<<" ";
        for(int i=2;i<=n;i++){
            arr[i] = arr[i-1] + arr[i-2];
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        }
	return 0;
}