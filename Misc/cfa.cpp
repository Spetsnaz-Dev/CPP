#include "bits/stdc++.h"
#define ll long long int
using namespace std;
int findResult(unordered_set<int>& st, int &maxx)
{
    int count = 0;
    for(int i=1; i<=1234567; i++)
    {
        count = 0;
        for(auto x : st)
        {
            int key = x ^ i;
            if(st.find(key) == st.end())
                break;
            else
                count++;
            if(count == st.size())
                return i;
        }
    }
    return -1;
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        unordered_set<int> st;
        int n, ele, maxx = INT_MIN;
        cin>>n;
        while(n--)
        {
            cin>>ele;
            st.insert(ele);
            maxx = max(maxx, ele);
        }
        cout<<findResult(st, maxx)<<"\n";
    }
    return 0;
}