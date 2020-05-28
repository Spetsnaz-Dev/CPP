// Find all anagrams in a string
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        vector<int> res;
        int n = s.size(), k = p.size(), i;
        
        if(n < k)
            return res;
        
        vector<int> v1(26), v2(26);
        for(int i=0; i<k; i++){
            v1[p[i] - 'a']++;
            v2[s[i] - 'a']++;
        }
        if(v1 == v2)
            res.push_back(0);
        
        for(int i=1; i<n-k+1; i++)
        {   
            int prev = s[i-1] - 'a';
            int next = s[i+k-1] - 'a';
            
            v2[prev]--;
            v2[next]++;
            
            if(v1 == v2)
                res.push_back(i);
            cout<<" "<<i;
        }
        cout<<"\n";
        return res;
    }
};