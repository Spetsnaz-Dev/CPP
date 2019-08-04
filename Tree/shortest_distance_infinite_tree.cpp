//Shortest distance in an infinite tree
#include<iostream>
using namespace std;
void longestDistance(int x, int y)
{
    if(x < y)
    {
        long temp = x;
        x = y;
        y = temp;
    }
    int c = 0;
    while (x != y)
    {
        if(x > y)
            x = x >> 1;
        c++;
        if(y > x)
        {
            y = y >>1;
            c++;
        }
    }
    cout<<c<<"\n";
}
int main(void)
{
    int t;
    cin>>t;
    while (t--)
    {
        long x, y;
        cin>>x>>y;
        longestDistance(x, y);
    }
    return 0;
}