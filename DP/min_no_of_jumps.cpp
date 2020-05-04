#include<bits/stdc++.h>
using namespace std;
int findJums(int arr[], int n){
    int maxReach = arr[0], jumps = 1, steps = arr[0];
    
    if(arr[0] == 0)
        return -1;
    
    int i = 1;
    for(; i<n; i++){
        if(i == n-1)
            return jumps;
        
        maxReach = max(maxReach, arr[i]+i);
        steps--;
            
        if(steps == 0){
            jumps++;
            
            if(i >= maxReach)
                return -1;
            
            steps = maxReach - i;
        }
    }
    return -1;
}
int main()
 {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<findJums(arr, n)<<"\n";
        }
	return 0;
}