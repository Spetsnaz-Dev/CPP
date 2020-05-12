class Solution {
public:
    float findSlope(int x1, int x2, int y1, int y2){
        // if((x2 - x1) == 0)
        //     return 0;
        float m = (float) (y2 - y1) / (float) (x2 - x1);
        return m;
    }
    bool checkStraightLine(vector<vector<int>>& coord) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = coord.size();
        
        if(n == 2)
            return  true;
        
        float m = findSlope(coord[0][0], coord[1][0], coord[0][1], coord[1][1]);
        for(int i=2; i<n; i++){
            float x = (float) findSlope(coord[i-1][0], coord[i][0], coord[i-1][1], coord[i][1]);
            
            if(x != m)
                return false;
        }
        return true;
    }};