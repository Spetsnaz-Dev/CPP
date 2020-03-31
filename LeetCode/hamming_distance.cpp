#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;

int hammingDistance(int x, int y) {
    int res = 0, bit_x, bit_y;
    while(x || y)
    {
        bit_x = x & 1;
        bit_y = y & 1;
        
        if(bit_x != bit_y)
            ++res;
        x >>= 1;
        y >>= 1;
    }
    return res;
}
int main()
{
    int x, y;
    cin>>x>>y;
    cout<<hammingDistance(x, y)<<"\n";

    return 0;
}