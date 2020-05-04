bool checkStrings(string s1, string s2, int curr){
        for(int i = curr; i < s1.size(); i++){
            if(s1[i] < s2[i])
                return false;
        }
        return true;
    }
    bool checkIfCanBreak(string s1, string s2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = s1.size();
        
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        
        int i=0;
        while(i < n and s1[i] == s2[i]){
            i++;
        }
        if(i == n)
            return true;
        
        bool flag = 0, res;
        if(s2[i] > s1[i])
            res = checkStrings(s2, s1, i);  //then s2 must be greater than s1
        else
            res = checkStrings(s1, s2, i);  //then s1 must be greater than s2
        
        return res;
    }