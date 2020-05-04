#include<bits/stdc++.h>
using namespace std;
int t, n, k;

bool cyclicShiftOperation(int arr[],
                        pair<int, int> pa, 
                        pair<int, int> pb, 
                        pair<int, int> pc,
                        vector<vector<int>>& v){
    int val1 = pa.first, val2 = pb.first, val3 = pc.first;
    int pos1 = pa.second, pos2 = pb.second, pos3 = pc.second;

    if(val1 > val2 and val1 > val3)
        return 0;

    arr[pos1-1] = val3, arr[pos3-1] = val2, arr[pos2-1] = val1;
    v.push_back({pos1, pos2, pos3});

    return 1;
}
void minSwaps(int arr[], int n, int k){
    int res = 0, i;
    
    int sorted[n];
    for(i=0; i<n; i++)
        sorted[i] = arr[i];
        
    sort(sorted, sorted+n);

    vector<vector<int>> ans;
    // while(res <= k)
    // {
        pair<int, int> pa, pb, pc;
        pa = pb = pc = {0, -1};
        for(i=0; i<n; i++){
        if(arr[i] != sorted[i])
        {
            if(!pa.first){
                pa = {arr[i], i+1};
                // cout<<i+1<<" ";
                continue;
            }
            else if(!pb.first){
                pb = {arr[i], i+1};
                // cout<<i+1<<" ";
                continue;
            }
            else{
                pc = {arr[i], i+1};
                // cout<<i+1<<"\n";
            }
        }
        if(pa.first and pb.first and pc.first){
            int flag = cyclicShiftOperation(arr, pa, pb, pc, ans);
            pa = pb = pc = {0, -1};
            if(flag == 1)
                res++;
        }
        }   // end for loop
    // }
    if(res >= k){
        //check if sorted
        for(int i=1; i<n; i++){
            if(arr[i] < arr[i-1]){
                res = -1;
                break;
            }
        }
    }
    cout<<res<<"\n";

    if(res == -1)
        return;
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++)
            cout<<ans[i][j]<<" ";
        cout<<"\n";
    }
}

// Driver program to test the above function
int main()
{
	// int t;
	cin>>t;
	while(t--)
	{
	    // int n, k;
	    cin>>n>>k;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    minSwaps(a, n, k);
	}
}