static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

// Method 1
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1);
        for(int i=1; i<=num; i++)
        {
            int pos = i & (i-1);
            res[i] = res[pos] + 1;
        }
        return res;
    }
};

// Method 2
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1);
        for(int i=1; i<=num; i++)
        {
            dp[i] = dp[i/2] + i%2;
        }
        return dp;
    }
};