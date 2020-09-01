#include "bits/stdc++.h"
#define base9 1e9
#define base7 1e7
#define ll long long int
#define ull unsigned long long int
#define pb push_back

using namespace std;
// Fast I/O
static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

bool notSafe(char str){
    return (str == '#' or str == '<' or str == '>' or str == '*');
}
string solve(string str)
{
    string res = "";
    bool numLock = true, end = true;
    int n = str.size(), i = 0;
    while (i < n)
    {
        if(str[i] == '*'){
            if(res.size() > 0)
                res.pop_back();
            else
                res = "";
        }
        else if(str[i] == '#')
            numLock = !numLock;

        else if(str[i] == '<')
            end = false;

        else if(str[i] == '>')
            end = true;
    
        else
        {
            if(end){
                res += str[i];
            }
            else
            {
                string t = "";
                while(i < n){
                    if(notSafe(str[i])){
                        res = t + res;
                        i--;
                        break;
                    }
                    t += str[i];
                    i++;
                }
            }
        }
        i++;
    }
    return res;
}
int main()
{
    // Input
    string s;
    cin>>s;

    // Output
    cout<<solve(s);
    cout<<"\n";

    return 0;
}
