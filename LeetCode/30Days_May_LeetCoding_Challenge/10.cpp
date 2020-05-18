// Find the town judge
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        vector<int> arr(n+1, 0);
        vector<int> brr(n+1, 0);
        
        // int n = trust.size();
        for(int i=0; i<trust.size(); i++){
            int a = trust[i][0];
            int b = trust[i][1];
            arr[b]++;
            brr[a]++;
        }
        
        int p = 0, J = -1;
        
        for(int i=1; i<=n; i++){
            if (brr[i]==0 && arr[i]==n-1){
                // p++;
                return i;
                // J = i;
            }
        }
        
//         if(p > 1){
//             J = -1;
//         }
        
        return J;
    }
};