class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        int left, right;
        set<vector<int> > st;
        vector<vector<int> > vv;
        // vector<int> temp;
        int n = v.size();
        if(n <= 2)
            return vv;
        sort(v.begin(), v.end());
        int i;  long long sum;
        for(i=0; i<n-2; i++)
        {
            left = i+1;
            right = n-1;
            while(left < right)
            {
                sum = v[i] + v[left] + v[right];
                if(sum > 0)
                    right--;
                else if(sum < 0)
                    left++;
                else {
                    // temp.push_back(v[i]);
                    // temp.push_back(v[left]);
                    // temp.push_back(v[right]);
                    st.insert({v[i], v[left], v[right]});
                    ++left; --right;
                    // vv.push_back(temp);
                    // temp.clear();
                    while(left < right && v[left] == v[left-1])
                        ++left;
                    while(right > left && v[right] == v[right+1])
                        --right;
                }
            }
        }
        
        for(auto itr = st.begin();itr!=st.end();++itr)
                vv.push_back(*itr);
                
        return vv;
    }
};