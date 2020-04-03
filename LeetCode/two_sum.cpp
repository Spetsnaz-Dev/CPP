class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> v;
    
        for(int i=0; i<nums.size(); i++) {
            int x = target - nums[i];
            if(mp.find(x) != mp.end()) {
                v.push_back(i);
                v.push_back(mp[x]);
                break;
            }
            else
                mp[nums[i]] = i;
        }
        return v;
    }
};

// Runtime: 8 ms, faster than 93.34% of C++ online submissions for Two Sum.
// Memory Usage: 8.2 MB, less than 100.00% of C++ online submissions for Two Sum.