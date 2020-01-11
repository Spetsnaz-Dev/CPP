class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& pro, string sWord) {
        sort(pro.begin(),pro.end());
        vector<vector<string>> res(sWord.size(),vector<string>{});
        for(auto p:pro){
            for(int i=0;i<sWord.size();i++){
                if(p[i]==sWord[i]){
                    res[i].push_back(p);
                }
                else
                    break;
            }
        }
        for(auto& v:res){
            if(v.size()>3)
                v.resize(3);
        }
        return res;
    }
};