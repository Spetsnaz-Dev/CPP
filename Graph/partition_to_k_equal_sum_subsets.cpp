static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
bool dfs(vector<int> arr, vector<bool>& vis, int idx, int k, int curr, int target)
{
    if(k==1)    return true;
    if(k <= 0)  return false;
    
    if(curr == target)
        return dfs(arr, vis, 0, k-1, 0, target);
    
    for(int i=idx; i<arr.size(); i++)
        if(!vis[i] and curr+arr[i] <= target)
        {
            vis[i] = 1;
            if(dfs(arr, vis, i+1, k, curr+arr[i], target))
                return true;
            
            vis[i] = 0;
        }
    return false;
}
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& arr, int k) {
        int n = arr.size();
        
        if(n < k)
            return false;
        
        long sum = 0;
        for(int x : arr)
            sum += x;
        if(sum % k != 0)
            return false;
        
        sum = sum / k;
        vector<bool> vis(n);
        return dfs(arr, vis, 0, k, 0, sum);
    }
};