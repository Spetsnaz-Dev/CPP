int numJewelsInStones(string j, string s) {
        unordered_map<char, int> mp;
        int stones = 0;
        
        int sizeJ = j.size(), sizeS = s.size();
        for(int i=0; i<sizeS; i++)
            mp[s[i]]++;
        
        for(int i=0; i<sizeJ; i++){
            if(mp.find(j[i]) != mp.end())
                stones += mp[j[i]];
        }
        return stones;
    }