#define _GLIBCXX_DEBUG
#include "bits/stdc++.h"
using namespace std;
#pragma GCC optimize "trapv"

int solve(int n){
    if(n == 1)
        return 0;
    else if(n == 2)
        return 1;

    int res = 1, count = 0, final = n, ele = 2;
    while (res < n and ele++)
    {
        res = (res*ele) / __gcd(res, ele);
        if(!st.count(res))
            count++;
        st.insert(res);
    }
    return count+1;
}
int main()
{
    int t, n;
    cin>>t;
    while (t--)
    {
        cin>>n;
        cout<<solve(n)<<endl;
    }
    return 0;
}