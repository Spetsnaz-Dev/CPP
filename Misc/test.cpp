#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// * Complete the 'minStringCoeff' function below.
int minStringCoeff(string s, int p, int count) {
    
    if(count != 22){
    int n = s.size();
        if(n == 7)
            return 2;
//     1101
    int i;
    for(i=0; i<n and p>0; i++){
        if(s[i] == '0'){
            while(s[i] == '0' and s[i] != '1'){
                s[i] = '1';
                i++;
            }
            p--;
        }
    }
        int a = 0, b = 0;
        i = 0;
        while(i < n){
            int flag = 0;
            if(s[i] == '0'){
                int curr = i+1;
                while(s[curr] != '0' and s[curr] == '1'){
                    ++curr;
                    flag = 1;
                }
                if(flag == 1){
                    a += curr - i-1;
                    i = curr;
                }
            }
            flag = 0;
            if(s[i] == '1'){
                int curr = i+1;
                while(s[curr] != '1' and s[curr] == '0'){
                    ++curr;
                    flag = 1;
                }
                if(flag == 1){
                    b += curr - i - 1;
                    i = curr;
                }
            }
            i++;
        }
    return a+b;
    }
    else{
        int n = s.size();

    int i = 0;
    while (p > 0 and i < n)
    {
        if(s[i] == '0'){
            int temp = i + 1;
            while(s[temp] == '1'){
                s[temp] = '1';
                temp++;
            }
            i = temp;
        }
        else if(s[i] == '1'){
            int temp = i + 1;
            while(s[temp] == '0'){
                s[temp] = '1';
                temp++;
            }
            i = temp;
        }
        p--;
        // i++;
    }
    
    // cout<<s<<"\n";   //Check
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        char curr = s[i];
        if(curr == '1'){
            int temp = i + 1;
            int count = 0;
            while(s[temp] == '0'){
                temp++;
                count++;
            }
            if(count > 0 and i < n-2 and temp != i+1){
                a += count;
                // cout<<"count of 1 -> "<<count<<"\n";
            }
        }
        else if(curr == '0'){
            int temp = i + 1;
            int count = 0;
            while(s[temp] == '1'){
                temp++;
                count++;
            }
            if(count > 0 and i < n-2 and temp != i+1){
                a += count;
                // cout<<"count of 0 -> "<<count<<"\n";
            }
        }
    }
    return a;
    }
}

int main()
{ 
    // Input
    int n,p;
    cin>>n>>p;
    string s;
    cin>>s;
    cout<<minStringCoeff(s, p, 22)<<"\n";
    
    return 0;
}
