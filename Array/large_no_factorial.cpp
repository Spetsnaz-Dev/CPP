#include<iostream>
using namespace std;
int multiply(int res[], int x, int arr_len) {
    int carry = 0;
    for(int i=0;i<arr_len;i++)
    {
        int prod = res[i]*x + carry;
        res[i] = prod % 10;
        carry = prod / 10;
    }
    while(carry) {
        res[arr_len] = carry % 10;
        carry /= 10;
        arr_len++;
    }
    return arr_len;
}
int main()
 {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        
        int res[10000];
        res[0] = 1;
        int arr_len = 1;
        for(int x =2; x <= n; x++)
            arr_len = multiply(res, x, arr_len);
        for(int i= arr_len-1; i>=0;i--)
            cout<<res[i];
        cout<<"\n";
    }
	return 0;
}