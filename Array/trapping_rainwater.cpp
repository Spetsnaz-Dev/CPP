#include<bits/stdc++.h>
using namespace std;
void collectRainWater(int arr[], int n) {
    int low= 0, high= n-1;
    int left_max=0, right_max= 0;
    int res = 0;        //Result
    while(low < high) {
        if(arr[low] < arr[high]) {
            if(arr[low] > left_max)
                left_max = arr[low];
            else {
                res += left_max - arr[low];
                low++;
            }
        } else {
            if(arr[high] > right_max)
                right_max = arr[high];
            else {
                res += right_max - arr[high];
                high--;
            }
        }
    }
    cout<<res<<"\n";
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
        collectRainWater(arr, n);
    }
    return 0;
}