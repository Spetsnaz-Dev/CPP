#include<iostream>
using namespace std;
void sumArray(int arr[], int n) {
    register int i,j;
    long excluding_curr=0, including_curr= arr[0];

    for(i=0;i<n;i++) {
        long excluding_curr=0, including_curr= arr[0];
        int excl_new = (including_curr > excluding_curr) ? including_curr : excluding_curr;
        
        including_curr += arr[i];
        excluding_curr = excl_new;
        cout<<max(excluding_curr, including_curr)<<" "; 
    }
    cout<<"\n";
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
        sumArray(arr, n);
    }
	return 0;
}