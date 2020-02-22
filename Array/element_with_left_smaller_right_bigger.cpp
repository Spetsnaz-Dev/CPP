#include<bits/stdc++.h>
using namespace std;

void findElement(int arr[], int n)
{
    int leftMax[n], rightMin[n];

    leftMax[0] = INT_MIN;
    int i;
    for(i=1;i<n;i++)
        leftMax[i] = max(leftMax[i-1], arr[i-1]);

    rightMin[n-1] = INT_MAX;
    for(i=n-1;i>=0;i--){
        rightMin[i-1] = min(arr[i], rightMin[i]);
        }

    for(i=1;i<n-1;i++)
        if(arr[i] >= leftMax[i] && arr[i] <= rightMin[i]){
            cout<<arr[i]<<"\n";
            return;
        }
    cout<<"-1\n";
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
        findElement(arr, n);
        }
	return 0;
}