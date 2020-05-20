// Permutation in a string
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int k = s1.size(), n = s2.size();
        
        if(k > n)
            return false;
        
        vector<int> v1(26), v2(26);
        for(int i=0; i<k; i++){
            v1[s1[i] - 'a']++;
            v2[s2[i] - 'a']++;
        }
        if(v1 == v2)
            return true;
        
        for(int i=1; i<n-k+1; i++)
        {   
            int prev = s2[i-1] - 'a';
            int next = s2[i+k-1] - 'a';
            
            v2[prev]--;
            v2[next]++;
            
            if(v1 == v2)
                return true;
        }
        return false;
    }
};