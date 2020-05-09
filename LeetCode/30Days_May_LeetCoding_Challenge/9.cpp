class Solution {
public:
    bool isPerfectSquare(int n) {
        for(long long i=1; i*i <= n; i++){
            if((n % i == 0) and (n / i == i))
                return true;
        }
        return false;
    }
};