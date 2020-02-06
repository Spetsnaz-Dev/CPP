// Longest Increasing Subsequence
#include<bits/stdc++.h>
using namespace std;
void LIS(int arr[], int size)
{
    int lis[size];
    lis[0] = 1;
    int j=0;
    for(int i=1;i<size;i++){
        lis[i] = 1;
        while(j < i)
        {
            if((arr[i] > arr[j]) && (lis[i] < lis[j] + 1))
                lis[i] = lis[j] + 1;
            j++;
        }
        j=0;
    }
    //returns max element in lis[]
    cout<<*max_element(lis, lis+size)<<"\n";
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
        LIS(arr, n);       
        }
	return 0;
}