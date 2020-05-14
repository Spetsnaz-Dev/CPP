class Solution {
public:
    string removeKdigits(string s, int k) {

        int n = s.size();
        if(n == k)
            return "0";
        
        string res;
        for(auto c : s)
        {
            while(k > 0 and !res.empty() and res.back() > c)
            {
                res.pop_back();
                --k;
            }
            res.push_back(c);
        }
        while(k > 0){
            res.pop_back();
            --k;
        }
        
        int start = 0;
        while(res[start] == '0' and start < res.size())
            ++start;
        
        if(res.empty() or start == res.size())
            return "0";
        else
            return res.substr(start, res.size() - start);
    }
};

static auto fastio = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();