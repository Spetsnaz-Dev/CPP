#include<bits/stdc++.h>
using namespace std;

bool isVowel(char c) 
{ 
    return (c=='a' || c=='A' || c=='e' || 
            c=='E' || c=='i' || c=='I' || 
            c=='o' || c=='O' || c=='u' || 
            c=='U'); 
} 

string reverseVowels(string str) {
    int l=0, r= str.length()-1;
        while(l<r) {
            if(isVowel(str[l]) && isVowel(str[r])) {
                char temp= str[l];
                str[l] = str[r];
                str[r] = temp;   
                l++; r--;
            }
            else if(isVowel(str[l]) && !isVowel(str[r]))
                r--;
            else if(!isVowel(str[l]) && isVowel(str[r]))
                l++;
            else {
                l++;
                r--;
            }
        }
    return str;
}
int main()
 {
	int t;
    cin>>t;
    while(t--) {
        string str;
        cin>>str;
        //getline(cin, str);
        cout<<reverseVowels(str)<<"\n";
    }
	return 0;
}