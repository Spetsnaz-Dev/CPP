#include "bits/stdc++.h"
using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
            // st.insert(arr[i]);
        }
        sort(arr.begin(), arr.end());
        int res = 0, curr = 1;
        for(int i=1; i<n; i++){
            if(arr[i] == arr[i-1]+1){
                curr++;
                res = max(res, curr);
            }
            else {
                curr = 1;
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}