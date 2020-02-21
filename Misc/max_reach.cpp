#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> height(n);
    int i, j;
    for(i = 0; i < n; i++)
        cin>>height[i];
    
    int dp[n];
    dp[n-1] = 0;

    // int max = height[n-1];
    for(i = n - 2; i >= 0; i--){
        for(j = i+1; j < n; j++){
            if(height[i] < height[j]){
                dp[i] = 1 + dp[j];
                break;
            }
            else
                dp[i] = 0;
        }
    }
    for(i = 0; i < n; i++)
        cout<<dp[i]<<" ";
    cout<<"\n";
    return 0;
}