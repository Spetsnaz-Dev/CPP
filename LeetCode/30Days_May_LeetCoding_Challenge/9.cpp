int findJudge(int n, vector<vector<int>>& trust) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        multimap<int, int> mp;
        
        // int n = trust.size();
        for(int i=0; i<trust.size(); i++)
            mp.insert({trust[i][0], trust[i][1]});
        
        for(auto i=1; i<=n; i++){
            if(mp.find(i) == mp.end()){
                
                int count = 0;
                for(auto x : mp){
                    if(x.second == i)
                        count++;
                }
                if(count == n-1)
                    return i;
            }
        }
        
        return -1;
    }