#include <bits/stdc++.h>
using namespace std;

int p = 131, M = 1000000007;
long long calcHash(string s)
{
    long long res = 0, n = s.size();
    for(int i=0; i<s.size(); i++){
        res += (int(s[i]) * pow(p, n-i-1));
    }
    return res % M;
}
bool authorize(string s, long long pass, string pass_str)
{
    long long n = stoi(s);
    if(n == pass)
        return true;
    
    for(char i='a'; i<='z'; i++){
        string t = pass_str + i;
        n = calcHash(t);
        cout<<n<<"\n";
        if(n == pass){
            cout<<"Hash matched is - "<<n<<"\n";
            return true;
        }
    }
    
    for(char i='A'; i<='Z'; i++){
        string t = pass_str + i;
        n = calcHash(t);
        cout<<n<<"\n";
        if(n == pass){
            cout<<"Hash matched is - "<<n<<"\n";
            return true;
        }
    }
    
    return false;
}
vector<int> authEvents(vector<vector<string>> events) {
    vector<int> res;
    long long pass;
    string pass_str;
    
    for (int i=0; i<events.size(); i++) {
        string e = events[i][0], curr = events[i][1];
        if(e == "setPassword"){
            long long hash = calcHash(curr);
            pass = hash;
            pass_str = curr;
        }
        else{
            bool ok = authorize(curr, pass, pass_str);
            if(ok)
                res.push_back(1);
            else
                res.push_back(0);
        }
    }
    return res;
}
int main(int argc, char const *argv[])
{}
