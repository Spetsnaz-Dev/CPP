#include<iostream>
using namespace std;
unsigned long int binomialCoeff(int n, int k)
{
    int res = 1;
    if(k> n-k)
        k = n-k;
    for(int i=0;i<k;i++)
    {
        res *= (n-i);
        res /= (i+1);
    }
    return res;
}
unsigned int catalan(int n)
{
    //res = 2n/(n+1);
    long int res = binomialCoeff(2*n, n);
    
    return res/(n+1);
}
int main()
 {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        
        cout<<catalan(n)<<"\n";
        }
	return 0;
}