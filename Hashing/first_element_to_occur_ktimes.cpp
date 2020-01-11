#include<iostream>
#include<map>
using namespace std;
int main()
 {
	int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        int arr[n];
        map<int, int> mp;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            mp[arr[i]]++;
        }
        for(int i=0;i<n;i++){
            if(mp.find(arr[i])->second >= k){
                cout<<arr[i]<<endl;
                break;
            }
        }
        }
	return 0;
}