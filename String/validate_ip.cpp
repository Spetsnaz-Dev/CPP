#include "bits/stdc++.h"
using namespace std;

string checkIPv6(string s)
{
    int i = 0;
    vector<string> v;
    string t;
    while(s[i])
    {
        if(s[i]!=':')
            t+=s[i];
        else
        {
            v.push_back(t);
            t="";
        }
        i++;
    }
    v.push_back(t);

    string hex = "0123456789abcdefABCDEF";
    for(int i=0; i<v.size(); i++)
    {
        if(v[i].size() == 0 or v[i].size() > 4)
            return "Neither";
        for (int j = 0; j < v[i].size(); j++)
        {
            if(hex.find(v[i][j]) == string::npos)
                return "Neither";
        }
    }
    return "IPv6";
}
string checkIPv4(string s)
{
    int i = 0;
    vector<string> v;
    string t;
    while(s[i])
    {
        if(s[i]!='.')
            t+=s[i];
        else
        {
            v.push_back(t);
            t="";
        }
        i++;
    }
    v.push_back(t);

    for(i=0; i<v.size(); i++)
    {
        int num = stoi(v[i]);

        if(v[i].size() == 0 or v[i].size() > 3)   return "Neither";

        if(v[i][0] == '0' and v[i].size() != 1)   return "Neither";

        for(int j=0; j<v[i].size(); j++)
            if(v[i][j] < '0' or v[i][j] > '9')
                return "Neither";

        if(num < 0 or num > 255)
            return "Neither";
    }
    return "IPv4";
}
string validIPAddress(string ip) {
    if(count(ip.begin(), ip.end(), '.') == 3)
        return checkIPv4(ip);
    else if(count(ip.begin(), ip.end(), ':') == 7)
        return checkIPv6(ip);
    else
        return "Neither";
}
int main()
{
    string IP;
    cin>>IP;
    cout<<validIPAddress(IP)<<endl;
}