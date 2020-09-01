#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
int findTimes(int a, int b)
{
    int diff = b - a;
    if(diff == 0)
        return 0;

    int exp = diff/6;
    if(diff < 12)
        return diff*2;
    else
        return diff*2 - exp;

    // return res;
}
int main()
{
    int t;
    cin>>t;
    int a, b;
    while(t--)
    {
        cin>>a>>b;
        cout<<findTimes(a, b)<<"\n";
    }
}