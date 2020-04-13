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

// Method 2
int findMaxLength(vector<int>& nums) {
        
        unordered_map<int,int> mymap;
        int sum = 0;
        int longest_subarray = 0;
        
        for(int i=0;i<nums.size();++i)
        {
            sum += nums[i]==0?-1:1;
            
            if(sum==0)
            {
                if(longest_subarray < i+1)
                    longest_subarray = i+1;
            }
            else if(mymap.find(sum)!=mymap.end())
            {
                if(longest_subarray < i-mymap[sum])
                    longest_subarray = i-mymap[sum];
            }
            else
                mymap[sum] = i;
        }    
    return longest_subarray;
}