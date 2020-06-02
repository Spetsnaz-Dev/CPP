static int speedUp = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        float dist;
        int n = points.size();
        
        vector<pair<float, int>> res;
        for(int i=0; i<n; i++)
        {
            int x = points[i][0], y = points[i][1];
            dist = (float)sqrt(x*x + y*y);
            res.push_back({dist, i});
        }
        sort(res.begin(), res.end());
        
        int i=0;
        vector<vector<int>> ans;
        while(i < k)
        {
            int pos = res[i].second;
            ans.push_back(points[pos]);
            i++;
        }
        return ans;
    }
};