#include "bits/stdc++.h"
using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

int findPos(string s, int i, int k)
{
    int n = s.size();
    int j = i+1;
    while (j < n)
    {
        if(s[j] == '1')
            return n+k;
        if(j - i > k and s[j] == '0')
            return j;
        j++;
    }
    return j;
}
// solver functionzz
int solve(string str, int n, int k)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int left_pos = findPos(str, i, k);
        int right_pos = findPos(str, left_pos, k);
        // cout<<left_pos<<" "<<right_pos<<endl;

        if(left_pos >= n)
            return count;

        if(right_pos - left_pos > k){
            str[left_pos] = '1';
            count++;
            i = left_pos;
        }
    }
    return count;
}
int main()
{ 
    // Input
    int t;
    cin>>t;
    string s;
    while (t--){
        int n, k; cin>>n>>k;
        cin>>s;
        // Output
        cout<<solve(s, n, k);

        cout<<"\n";
    }
    return 0;
}
