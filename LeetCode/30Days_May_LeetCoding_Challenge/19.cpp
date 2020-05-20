// Online Stock Spanner
// Method 1
class StockSpanner {
public:
    vector<int> prices, res;
    
    StockSpanner() {
        // prices.clear();
        // res.clear();
    }
    
    int next(int price) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int ans = 1;
        for(int i=res.size()-1; i>=0; i--)
        {
            if(prices[i] <= price)
            {
                ans += res[i];
                i -= res[i];    //jump to the location till when price is surely lower than current price
                ++i;
            }
            else
                break;
        }
        prices.push_back(price);
        res.push_back(ans);
        
        return ans;
    }
};

// Method 2
class StockSpanner {
public:
    stack<pair<int, int>> s;
    StockSpanner() {}
    
    int next(int price) {
        int res = 1;
        while (!s.empty() && s.top().first <= price) {
            res += s.top().second;
            cout<<s.top().first<<" ";
            s.pop();
        }
        s.push({price, res});
        return res;
    }
};