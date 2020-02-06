#include<bits/stdc++.h>
using namespace std;
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
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>dep[i];
        sort(arr, arr+n);
        sort(dep, dep+n);
        int i = 1, j = 0;
        int max_platforms = 1, count = 1;
        while (i < n && j < n)
        {
            if(arr[i] <= dep[j]){
                count += 1;
                i++;
                max_platforms = max(max_platforms, count);
            }
            else {
                j++;
                count --;
            }
        }
        cout<<max_platforms<<"\n";
        }
	return 0;
}