static int speedUp = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
bool compare(const vector<int> &a, const vector<int> &b){
        return (a[0] - a[1] < b[0] - b[1]);
    }
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& cost) {
        int n = cost.size(), res = 0;

        sort(cost.begin(), cost.end(), compare);
        
        for(int i=0; i<n; i++)
        {
            if(i < n/2)
                res += cost[i][0];
            else
                res += cost[i][1];
        }
        return res;
    }
};