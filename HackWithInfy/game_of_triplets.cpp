#include<iostream>
using namespace std;
typedef long long int ll;

ll playGame(ll a, ll b, ll c)
{
    a = (a + b) / 2;    b = (b + c) / 2;    c = (c + a) / 2;

    if((a & 1) || (b & 1) || (c & 1))
        return 1;
    return 1 + playGame(a, b, c);
}
int main()
{
    ll a, b, c;
    cin>>a>>b>>c;

    if((a & 1) || (b & 1) || (c & 1))
        cout<<0<<"\n";
    else
        cout<< 1 + playGame(a, b, c)<<"\n";

    return 0;
}