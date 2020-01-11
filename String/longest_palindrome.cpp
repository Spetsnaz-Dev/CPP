#include<bits/stdc++.h>
using namespace std;
void findLongestPalindrome(string str) {
    int n= str.length();
    bool table[n][n];
    memset(table, 0, sizeof(table));

    int i, j;
    for(i=0;i<n;i++)
        table[i][i]= 1;
    int max_length= 1;

    //FOR SUBSTRING OF LENGTH 2
    int start= 0, count= 0;
    for(i=0;i<n-1;++i) {
        if(str[i] == str[i+1]) {
            table[i][i+1] = 1;
            max_length= 2;
            count++;
            if(count == 1)
                start= i;
        }
    }
    //For SUBSTRING OF LENGTH >=3
    for(int k=3; k<=n; ++k) {
        for(i=0; i < n-k+1; ++i) {
            int j= i+k-1; //ending index of Palindrome String
            
            if(table[i+1][j-1] && str[i] == str[j]) {
                table[i][j] = 1;

                if(k > max_length) {
                    max_length= k;
                    start= i;
                }
            }
        }
    }
    int total_len=0;string res="";
    for(i= start; i<= start+max_length-1; i++){
        total_len++;
        res += str[i];
    }
    cout<<total_len<<endl<<res;
    cout<<"\n";
}

int main() {
    int t;
    cin>>t;
    //while(t--) {
        string s;
        //string s= "kjqlrzzfmlvyoshiktodnsjjp";
        cin>>s;
        findLongestPalindrome(s);
    //}
    return 0;
}