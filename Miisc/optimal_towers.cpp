#include<bits/stdc++.h>
using namespace std;
void optimalTowers(int arr[], int k, int n) {
    int count=0;
    int it;
    int j=2;
    for(int i=1;i<n;i++)
    {
        if(j>k){j=i-it+1;count++; cout<<i<<"k";}
        if(arr[i]>arr[i-1] && arr[i+1]<arr[i])
        {
            it=i;cout<<it<<"i";
        }
        j++;
    }
    cout<<count<<"\n";
}
int main() {
    int k;
    cin>>k;
    int m;
    cin>>m;
    int arr[m];
    for(int i=0;i<m;i++) 
        cin>>arr[i];
    optimalTowers(arr, k, m);

    return 0;
}