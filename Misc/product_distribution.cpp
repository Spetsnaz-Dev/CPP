#include "bits/stdc++.h"
#define mod 1000000007;
using namespace std;
int productDistribute(vector<int>& arr, int m)
{
    int n = arr.size();
    if(n == 0)
        return 0;

    sort(arr.begin(), arr.end());
    int times;
    if(n%m == 0)
        times = n/m;
    else
        times = n/m - 1;

    long res = 0, sum, k = 1, i = 0;
    for(i=0; i<n and k <= times; i+=m){
        sum = 0;
        for(int j=i; j<i+m;j++){
            sum += arr[j];
        }
        res += (k*sum) % mod;
        ++k;
    }
    if(i == n-1){
        return res;
    }
    else{
        sum = 0;
        while(i < n){
            sum += arr[i];
            i++;
        }
        return res += (k * sum) % mod;
    }
}
int main()
{
    int n, m;
    cin>>n>>m;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<productDistribute(arr, m)<<"\n";

    return 0;
}