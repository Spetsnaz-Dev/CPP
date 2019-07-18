#include<bits/stdc++.h>
using namespace std;
int main()
{
int t;
cin >> t;
while (t--)
{
map<string, int> m;
string s;
cin >> s;
int len = s.length();
for (int i = 0; i < len; i++)
{
for (int l = 1; i + l - 1 < len; l++)
{
string t = s.substr(i, l);
sort(t.begin(), t.end());
m[t]++;
}
}
long long ans = 0;
for (map<string, int>::iterator it = m.begin(); it != m.end(); ++it)
ans += (long long)(it->second) * (it->second - 1) / 2;
cout << ans << endl;
}
return 0;
}