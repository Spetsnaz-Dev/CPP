//Sum of f(a[i], a[j]) over all pairs in an array of n integers
#include<bits/stdc++.h>
using namespace std;
void findSum(int arr[], int n)
{
    int sum;
    long res=0;
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
        {
            if(abs(arr[j] - arr[i]) > 1)
            {
                sum = (arr[j] - arr[i]);
                res+= sum;
                //arr[i] = arr[j] = sum;
            }
        }
        cout<<res<<"\n";
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        findSum(arr, n);
    }
    return 0;
}