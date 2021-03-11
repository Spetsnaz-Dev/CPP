#include "bits/stdc++.h"
using namespace std;

int threeSumClosest(vector<int>& arr, int target) {
        sort(begin(arr), end(arr));
        
        long res = INT_MAX, old_diff = INT_MAX, sum, n = arr.size();
        for(int i=0; i<n-2; i++){
            int l = i+1, r = n-1;
            while(l < r){
                sum = arr[i] + arr[l] + arr[r];
                int new_diff = abs(sum - target);
                
                if(new_diff == 0)   return sum;
                
                if(new_diff < old_diff){
                    res = sum;
                    old_diff = new_diff;
                }
                if(sum < target)
                    l++;
                else
                    r--;
            }
        }
        return res;
    }
int main()
{
    vector<int> arr = {1,1,1,1};
    int target = 0;
    cout<<threeSumClosest(arr, target)<<"\n";
}