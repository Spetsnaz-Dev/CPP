int majorityElement(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = arr.size();
        unordered_map<int, int> mp;
        
        for(int i=0; i<n; i++)
            mp[arr[i]]++;
        
        int res = 0;
        for(int i=0; i<n; i++)
            if(mp[arr[i]] > n/2){
                res = arr[i];
                break;
            }
        return res;
    }