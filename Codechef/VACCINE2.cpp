#include "bits/stdc++.h"
using namespace std;

int findDays(int n, int d, int risk)
{
    if(d == 1)  return n;

    int normal = n - risk;
    // cout<<risk<<" - "<<normal<<"\n";
    int day1 = (ceil)(risk/d);
    int day2 = (ceil)(normal/d);
    // cout<<day1<<" - "<<day2<<"\n";
    return day1 + day2;
}
int main()
{
    int n, d, t;
    cin>>t;
    while (t--)
    {
        cin>>n>>d;
        int age, risk = 0;
        for (int i = 0; i < n; i++)
        {
            cin>>age;
            if(age >= 80 or age <= 9)
                risk++;
        }
        cout<<findDays(n, d, risk)<<"\n";
    }
}