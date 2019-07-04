#include<bits/stdc++.h>
using namespace std;

int remainderWith7(string s) {
    int series[] = {1, 3, 2, -1, -3, -2};
    int i, i_series=0, sum=0, number, digit;
    for(i=s.length()-1; i>=0; i--) {
        digit = s[i] - '0';
        sum = sum + series[i_series++]*digit;
        i_series = i_series % 6;

        number= sum % 7;
    }
    if(number < 7)
        number = (number+7) % 7;

    return number;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        cout<<remainderWith7(s)<<"\n";
    }
    return 0;
}