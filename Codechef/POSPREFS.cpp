#include "bits/stdc++.h"
using namespace std;

int t, n, k;
// Krantiveer
int main()
{
    // int t;
    cin>>t;
    while (t--)
    {
        // int n, k;
        cin>>n>>k;        
        // build array
        vector<int> arr(n+1);
        for(int i=0; i<n; i++)
            arr[i] = i+1;
        
        // check odd-even and fill negative elements
        if(n%2 == 0){
            for (int i = 0; i < n; i++)
            {
                if(arr[i]%2 != 0)
                    arr[i] = -arr[i];
            }
        }
        else if(n%2 != 0){
            for (int i = 0; i < n; i++)
            {
                if(arr[i]%2 == 0)
                    arr[i] = -arr[i];
            }
        }

        // for(int i=0; i<n; i++)
        //     cout<<arr[i]<<" ";
        // cout<<"\n";

        int count = 0, i = n-1;
        for(int i : arr)
            if(i > 0)
                count++;
            
        int diff = abs(k - count);
        if(count < k){
            while(i >= 0 and diff){
                if(arr[i] < 0){
                    arr[i] = abs(arr[i]);
                    diff--;
                }
                i--;
            }
        }
        else if(count > k){
            while(i >= 0 and diff){
                if(arr[i] > 0){
                    arr[i] = -arr[i];
                    diff--;
                }
                i--;
            }
        }
        // print ans
        for(int i=0; i<n; i++)
            cout<<arr[i]<<" ";
        cout<<"\n";
    }
}