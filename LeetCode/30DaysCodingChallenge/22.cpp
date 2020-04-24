    // LRU Cache
    list<pair<int, int>> dq;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    int size;
    
    LRUCache(int capacity) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        size = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        
        auto it = mp[key];
        int val = it->second;
        dq.erase(it);
        
        dq.push_front({key, val});
        mp[key] = dq.begin();
        
        return val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) == mp.end()){
            if(dq.size() == size){
                auto last = dq.back();
                mp.erase(last.first);
                dq.pop_back();
            }
        }
        else{
            auto it = mp[key];
            dq.erase(it);
        }
        
        dq.push_front({key, value});
        mp[key] = dq.begin();
    }