class Solution {
public:
    string frequencySort(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = s.size();
        
        unordered_map<char, int> mp;
        for(int i=0; i<n; i++)
            mp[s[i]]++;
        
        vector<pair<int, char>> v;
        for(auto i=mp.begin(); i!=mp.end(); i++)
        {
            char c = i->first;
            int count = i->second;
            v.push_back({count, c});
        }
        
        sort(v.begin(), v.end(), greater<pair<int, char>>());
        string res = "";
        for(int i=0; i<v.size(); i++)
        {
            int k = v[i].first;
            char c = v[i].second;
            res = res + string(k, c);
        }
        return res;
    }
};