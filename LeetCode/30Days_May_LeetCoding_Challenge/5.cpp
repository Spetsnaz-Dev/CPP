int firstUniqChar(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int res = 0, n = s.size();
        unordered_map<char, int> mp;
        
        for(int i=0;i<n;i++)
            mp[s[i]]++;
        
        for(int i=0;i<n;i++){
            if(mp[s[i]] == 1)
                return i;
        }
        return -1;
    }