static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& arr, vector<vector<int>>& brr) {
        vector<vector<int>> res;
        
        int n = arr.size(), m = brr.size(), i = 0, j = 0;
        
        if(n == 0 or m == 0)
            return res;
        
        while(i < n and j < m)
        {
            if(arr[i][1] < brr[j][0])
                i++;
            else if(brr[j][1] < arr[i][0])
                j++;
            else {
                int start = max(arr[i][0], brr[j][0]);
                int end = min(arr[i][1], brr[j][1]);
                
                res.push_back({start, end});
                
                if(arr[i][1] <= res.back()[1])
                    i++;
                if(brr[j][1] <= res.back()[1])
                    j++;
            }
        }
        return res;
    }
};