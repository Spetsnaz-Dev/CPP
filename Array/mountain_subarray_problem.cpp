vector<bool> processQueries(int arr[], int n, vector<pair<int, int>> &queries,
                            int q) {
    int left[n], right[n];
    
    int pos = 0;
    left[0] = 0;
    for(int i=1;i<n; i++){
        if(arr[i] > arr[i-1])
            pos = i;
        left[i] = pos;
    }
    
    pos = n-1;
    right[n-1] = n-1;
    for(int i=n-2;i>=0; i--){
        if(arr[i] > arr[i+1])
            pos = i;
        right[i] = pos;
    }
    
    vector<bool> ans;
    for(int i=0; i<queries.size(); i++){
        int l = queries[i].first, r = queries[i].second;
        
        if(right[l] >= left[r])
            ans.push_back(1);
        else
            ans.push_back(0);
    }
    return ans;
}