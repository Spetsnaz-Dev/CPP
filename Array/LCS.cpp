#include<bits/stdc++.h>
using namespace std;

int findLCS(int arr[], int n) {
    unordered_set<int> s;
    int i, res=0;
    for(i=0;i<n;i++)
        s.insert(arr[i]);

    for(i=0;i<n;i++) {
        if(s.find(arr[i] - 1) == s.end()) {
            int temp= arr[i];

            while(s.find(temp) != s.end())
                temp++;

            res = max(res, temp-arr[i]);
        }
    }
    return res;
}
int main()
 {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];

        cout<<findLCS(arr, n)<<"\n";
    }
	return 0;
}