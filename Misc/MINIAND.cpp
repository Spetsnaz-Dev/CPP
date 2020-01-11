#include<bits/stdc++.h>
using namespace std;

int n;
int main(){
	int t;
	cin >> t;
	while (t--){
		cin >> n;

        int arr[n+1];
        int res[n+1];
		for(int i=0;i<n;i++)
            cin>>arr[i];

		for(int i=1;i<=n;i++){
			arr[i] += arr[i-1] + (res[i]%2 == 0);
            cout<<arr[i]<<" ";
		}
		int q;
		cin >> q;
		while (q--){
			int l, r;
			cin >> l >> r;
			int val = arr[r] - arr[l-1];
			if (val){
				cout << "EVEN\n";
			}
			else{
				cout << "ODD\n";
			}
		}
		memset(res, 0, sizeof(arr));
	}
}