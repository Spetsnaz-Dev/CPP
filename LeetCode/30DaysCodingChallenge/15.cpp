vector<int> productExceptSelf(vector<int>& v) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        
        int n = v.size();
        int pre[n], suf[n];
        pre[0] = suf[n-1] = 1;
        
        int i=1, j=n-2;
        while(i<n and j>=0){
            
            pre[i] = pre[i-1] * v[i-1];
            suf[j] = suf[j+1] * v[j+1];
            
            j--;    i++;
        }
        vector<int> prod(n);
        for(int i=0; i<n; i++)
            prod[i] = pre[i] * suf[i];
        
        return prod;
    }