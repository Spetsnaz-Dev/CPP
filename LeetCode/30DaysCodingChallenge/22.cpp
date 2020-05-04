int subarraySum(vector<int>& arr, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = arr.size();

        if(n == 0)
            return 0;
    
        unordered_map<int, int> mp;
        int curr = 0, res = 0;
    
        for (size_t i = 0; i < n; i++)
        {
            curr += arr[i];

            if(curr == k)
                res ++;

            if(mp.find(curr - k) != mp.end())
                res += mp[curr - k];
        
            mp[curr]++;
        }
        return res;
    }