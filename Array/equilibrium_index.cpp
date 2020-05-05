#include <iostream>
#include <stdio.h>
using namespace std;

int findEquilibrium(int arr[], int n)
{
    int preSum = 0, postSum = 0;
    for(int i=0; i<n; i++){
        preSum += arr[i];
    }

    for(int i=0; i<n; i++){
        postSum = postSum + arr[i];
        // cout<<postSum<<" ";
        if(postSum == preSum){
            // cout<<"Now eql sum is - "<<postSum<<endl;
            return i;
        }
        preSum = preSum - arr[i];
    }
    return -1;
}

int main() {
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		cout<<findEquilibrium (a,n)<<endl;
	}
	// your code goes here
	return 0;
}// } Driver Code Ends