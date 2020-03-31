class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       
        sort(nums.begin(),nums.end());
        set <vector<int> > myset;      
        int i,left,right;
        int n = nums.size();
       
        for(i=0;i<n-2;++i)
        {
            left = i+1;
            right = n-1;
            while(left < right)
            {
                long long sum = nums[i]+nums[left]+nums[right];
                if(sum < 0)
                    ++left;
                else if(sum > 0)
                    --right;
                else{
                    myset.insert({nums[i], nums[left], nums[right]});
                    ++left;
                    --right;
                    while(left < right and nums[left] == nums[left-1])
                        left++;
                    while(left < right and nums[right] == nums[right+1])
                        right--;
                }
            }
        }
        vector<vector<int> > result;       
        for(auto itr = myset.begin();itr!=myset.end();++itr)
        {
            result.push_back(*itr);
        }
        return result;
    }
};