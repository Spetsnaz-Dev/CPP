// https://practice.geeksforgeeks.org/problems/rob-the-houses/1
#include "bits/stdc++.h"
using namespace std;
int kadanesAlgo(int arr[], int n)
{
    int msf = 0, meh = INT_MIN;
    for (int i = 0; i < n; i++){
        msf = msf + arr[i];
        if(msf < arr[i])
            msf = arr[i];
        if(meh < msf)
            meh = msf;
    }
    return meh;
}
int findMAX(int arr[], int n)
{
    int totalMoney = 0;
    for (int i = 0; i < n; i++){
        totalMoney += arr[i];
        arr[i] = -arr[i];
    }
    totalMoney = totalMoney + kadanesAlgo(arr, n);
    return totalMoney;
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int rob1 = kadanesAlgo(arr, n);
        int rob2 = findMAX(arr, n);

        if(rob1 > rob2)
            cout<<rob1<<"\n";
        else
            cout<<rob2<<"\n";
    }
    return 0;
}