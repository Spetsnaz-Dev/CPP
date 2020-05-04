queue<int> q;
    unordered_map<int, int> mp;
    FirstUnique(vector<int>& nums) {
        
        // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        
        for(int i=0; i<nums.size(); i++)
            mp[nums[i]]++;
        
        for(int i=0; i<nums.size(); i++){
            if(mp[nums[i]] == 1)
                q.push(nums[i]);
        }
    }
    
    int showFirstUnique() {
        
        if(mp[q.front()] > 1)
            q.pop();
        
        if(q.empty())
            return -1;
        else
            return q.front();
    }
    
    void add(int value) {
        mp[value]++;
        if(mp[value] > 1 and q.front() == value)
            q.pop();
        else if(mp[value] == 1)
            q.push(value);
    }
};