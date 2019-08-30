#include<bits/stdc++.h>
using namespace std;

int primeSum(int n) 
{ 
    bool prime[n + 1]; 
    memset(prime, true, n + 1); 
  
    for (int p = 2; p * p <= n; p++) { 
        if (prime[p] == true) { 
            for (int i = p * 2; i <= n; i += p) 
                prime[i] = false; 
        } 
    } 
    int sum = 0; 
    for (int i = 2; i <= n; i++) 
        if (prime[i]) 
            sum += i; 
    return sum; 
} 
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        cout<<primeSum(n)<<"\n";
    }
    return 0;
}