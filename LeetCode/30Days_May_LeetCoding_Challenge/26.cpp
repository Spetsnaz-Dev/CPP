static int speedUp = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // Fast I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = nums.size();
        
        if(n == 0 or n == 1)
            return 0;
        
        unordered_map<int, int> mp;
        int res = 0, sum = 0;
        
        mp[0] = -1; //for handling first element as 0 so index is -1 default
        for(int i=0; i<n; i++){
            sum += nums[i] == 0 ? -1 : 1;
            
            if(mp.find(sum) != mp.end()){
                res = max(res, i - mp[sum]);
            }
            else
                mp[sum] = i;
        }
        return res;
    }
};