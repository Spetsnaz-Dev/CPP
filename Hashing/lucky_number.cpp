//LUCKY NUMBER

// -------------- METHOD 1 ------------------//
#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool isLucky(string str)
{
    unordered_map<ll, ll> mp;
    for(int i=0;i<str.length();i++)
    {
        ll prod= 1;
        for(int j=i;j<str.length();j++)
        {
            prod *= (str[j] - '0');
            if(mp[prod])
                return 0;
            mp[prod]++;
        }
    }
    return 1;
}
int main()
 {
	int t;
    cin>>t;
    while(t--) {
        string n;
        cin>>n;
        //unordered_map<ll, ll> mp;
        cout<<isLucky(n)<<"\n";
    }
    return 0;
 }
 // -------------- METHOD 2 ------------------//
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long

// bool isLucky(string str, int start, unordered_map<ll, ll> &mp)
// {
//     ll prod=1;
//     for(int i=start;i<str.length();i++)
//     {
//         prod *= str[i] - '0';
//         cout<<"Test-- "<<prod<<"\n";
//         if(mp[prod])
//             return false;
//         mp[prod]++;
//     }
//     return true;
// }
// int main()
//  {
// 	int t;
//     cin>>t;
//     while(t--) {
//         string n;
//         cin>>n;
//         unordered_map<ll, ll> mp;
//         int flag=1;
//         for(int i=0;i<n.length();i++)
//         {
//             if(!isLucky(n, i, mp))
//             {
//                 flag=0;
//                 break;
//             }
//         }
//     cout<<flag<<"\n";
//     }
// 	return 0;
// }