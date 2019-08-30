#include<bits/stdc++.h>
using namespace std;
int findSubarraySUM(int arr[], int n)
{
    int meh = 0;
    int msf = INT_MIN;
    for(int i=0;i<n;i++)
    {
        meh += arr[i];
        if(meh < arr[i])
            meh = arr[i];
        if(meh > msf)
            msf = meh;
    }
    return msf;
}
int findSubsequenceSUM(int arr[], int n)
{
    //int sum = 0;
    int curr_sum= 0;
    //int prev_sum=0;
    int i=0;
    int flag = 0;
    while(i<n)
    {
        if(arr[i]>0)
        {
            curr_sum += arr[i++];
            flag = 1;
        }
        else
        {
            i++;
        }
    }
    if(flag == 0)
        {
            curr_sum = arr[0];
            for(int i=1;i<n;i++)
                if(arr[i]> curr_sum)
                    curr_sum = arr[i];
        }
    return curr_sum;
}
void printSUM(int arr[], int n)
{
    int subarray_sum= findSubarraySUM(arr, n);
    int subseq_sum = findSubsequenceSUM(arr, n);
    cout<<subarray_sum<<" "<<subseq_sum<<"\n";
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        printSUM(arr, n);
    }
    return 0;
}