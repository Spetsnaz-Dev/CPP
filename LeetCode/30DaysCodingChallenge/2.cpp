#include "iostream"
using namespace std;

bool isHappy(int n) {
        if(n == 0 or n == 1)
            return n;
        int sum , r, d, prev = n, count = 0;
        while(1)
        {
            count++;
            sum = 0;
            while(n)
            {
                r = n % 10;
                n /= 10;
                sum += r*r;
            }
            if(sum == 1 or sum == 0)
                    return sum;
            if(sum == prev or count > 15)
                return 0;
            n = sum;
        }
    // return sum;
}
int main()
{
    int n;
    cin>>n;
    cout<<isHappy(n)<<"\n";

    return 0;
}