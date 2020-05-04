vector<int> configureProjectPresentation(int n, vector<vector<int>> arr) {
    unordered_set<int> st1; //for node 1 only
    unordered_set<int> st2; //for node 2 only
    
    vector<int> ans;    //for answer
    
    for(int i = 0; i < n; i+=n){
        int r = arr[i][1];
        for(int j = 0; j < r; j++){
            
            int low = min(arr[i+j][0], arr[i+j][1]);
            int high = max(arr[i+j][0], arr[i+j][1]);
            
            if(low == 1){
                st1.insert(high);
            }
            else if(low == 2){
                st2.insert(high);
            }
            else if(st2.find(low) != st2.end() or st2.find(high) != st2.end()){
                st2.insert(low);
                st2.insert(high);
            }
            else if(st1.find(low) != st1.end() or st1.find(high) != st1.end()){
                st1.insert(low);
                st1.insert(high);
            }
        }
        int flag = 0;
        for(auto i=st1.begin(); i!=st1.end(); i++){
            if(st2.find(*i) == st2.end()){
                flag = 1;
                ans.push_back(*i);
            }
        }
        st1.clear();   st2.clear();
        if(flag == 0)
            ans.push_back(-1);
    }
    return ans;
}