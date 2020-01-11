#include<iostream>
using namespace std;
int countBits(int n)
{
    int setBitCount=0;
    while(n)
    {
        setBitCount += n & 1;
        n = n >> 1;
    }
    return setBitCount;
}
int main()
{
    int n;
    cin>>n;
    int setBits = 0;
    for(int i=1;i<=n;i++)
        setBits += countBits(i);
    
    cout<<setBits<<endl;

    return 0;
}