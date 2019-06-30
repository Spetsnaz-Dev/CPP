#include<bits/stdc++.h>
using namespace std;

string multiplyStrings(string s1, string s2) {
   //Your code here
   int sign = 1;
   if(s1[0] == '-' && s2[0] == '-'){
       sign = 1;
       s1= s1.substr(1);
       s2= s2.substr(1);
   }
   else if(s1[0] == '-' && s2[0] != '-') {
       sign = -1;
       s1= s1.substr(1);
   }
   else if(s2[0] == '-' && s1[0] != '-') {
       s2= s2.substr(1);
       sign= -1;
   }
   int m= s1.length();
    int n= s2.length();
    //cout<<"s1- "<<s1<<endl<<"s2- "<<s2<<endl;

    if(n == 0 || m == 0)
        return "0";
    
    if((s1.at(0) == '-' || s2.at(0) == '-') &&  
        (s1.at(0) != '-' || s2.at(0) != '-' )) 
        cout<<"-"; 
    if(s1.at(0) == '-' && s2.at(0)!='-') 
        { 
            s1 = s1.substr(1); 
        } 
        else if(s1.at(0) != '-' && s2.at(0) == '-') 
        { 
            s2 = s2.substr(1); 
        } 
        else if(s1.at(0) == '-' && s2.at(0) == '-') 
        { 
            s1 = s1.substr(1); 
            s2 = s2.substr(1); 
        } 
    int i,j;
    vector<int> res(n+m, 0);
    int carry, n1, n2, i_n1, i_n2;
    i_n1 = 0; i_n2 = 0;
    for(i=m-1;i>=0;i--) {
        n1= s1[i] - '0';
        carry= 0;
        i_n2=0;
        for(j=n-1;j>=0;j--) {
            n2= s2[j] - '0';
            int sum= n1*n2 + res[i_n1 + i_n2] + carry;

            carry = sum / 10;
            res[i_n1 + i_n2] = sum % 10;
            i_n2++;
        }
        if(carry > 0)
            res[i_n1 + i_n2] += carry;

        i_n1++;
    }
    i= res.size()-1;
    //cout<<"I - "<<i<<endl;
    while(i>=0 && res[i]== 0 )
        i--;
    string s= "";
    for(int j= i; j>=0;j--)
        s+= to_string(res[j]);
    
    if(sign == -1)
        return '-'+s;
    else
        return s;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        string s1 = "675356291270936062618792023759228973612931947845036106320615547656937452547443078688";
        string s2= "3149206892664950487172722610615949091771159776736563948129390885096385611598481030444";
        //cin>>s1>>s2;
        cout<<multiplyStrings(s1, s2)<<"\n";
    }
    return 0;
}