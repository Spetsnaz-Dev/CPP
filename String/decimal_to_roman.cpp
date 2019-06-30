#include<bits/stdc++.h>
using namespace std;

void convertRoman(int number) {
    int arr[] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
    string symbols[] = { "I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M" };
    int i=12;
    while(number > 0) {
        int div= number/arr[i];
        number= number % arr[i];

        while(div--) {
            cout<<symbols[i];
        }
        i--;
    }
    cout<<"\n";
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        convertRoman(n);
    }
    return 0;
}