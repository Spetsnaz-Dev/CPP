// Min Stack
// Solved by using Array Method 
// also can be solved using Two Stacks or Stack<pair<int, int>> 
class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> min;
    vector<int> st;
    MinStack() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    void push(int x) {
        if(st.empty()){
            st.push_back(x);
            min.push_back(x);
        } else {
            st.push_back(x);
            if(min.back() < x)
                min.push_back(min.back());
            else
                min.push_back(x);
        }
    }
    
    void pop() {
        st.pop_back();
        min.pop_back();
    }
    
    int top() {
        if(!st.empty())
            return st.back();
        return -1;
    }
    
    int getMin() {
        if(!min.empty())
            return min.back();
        return -1;
    }
};
// Runtime: 32 ms
// Memory Usage: 14.8 MB