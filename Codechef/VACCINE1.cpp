#include "bits/stdc++.h"
using namespace std;

int main()
{
    int d1, v1, d2, v2, p;
    cin>>d1>>v1>>d2>>v2>>p;

    int days = 0, vaccines = 0;
    while (vaccines < p)
    {
        if(days >= d1)
            vaccines += v1;
        if(days >= d2)
            vaccines += v2;
        days++;
    }
    cout<<days-1<<"\n";
}