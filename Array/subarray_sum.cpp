//Subarray with given sum
#include<bits/stdc++.h>
using namespace std;

int subarray_Sum(int arr[], int n, int sum) {
    unordered_map<int, int> m;
    int curr_sum=0, count=0;

    for(int i=0;i<n;i++) {
        curr_sum += arr[i];

        if(curr_sum == sum)
            count++;

        if(m.find(curr_sum - sum) != m.end())
            count += (m[curr_sum - sum]);
            
        m[curr_sum]++;
    }
    return count;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int sum;
        cin>>sum;
    cout<<subarray_Sum(arr, n, sum)<<"\n";
    }
    return 0;
}