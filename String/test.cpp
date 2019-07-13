#include<iostream>
using namespace std;
void reverse(long long number) {
    
    if(number == 0)
        return;
        
    int digit = number % 10;
    cout<<digit;
    
    reverse(number/10);
}
int main()
 {
	int t;
    cin>>t;
    while(t--) {
        long long n;
        cin>>n;
        while(n%10 == 0)
            n /= 10;
        reverse(n);
        cout<<"\n";
            }
	return 0;
}