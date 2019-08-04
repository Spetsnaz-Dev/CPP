//Binary Tree Kth level sum
#include<bits/stdc++.h>
using namespace std;
void findSumTree(string str, int k)
{
    int level = -1;
    int len = str.length();
    //int arr[20];  //max level is 20 given
    //memset(arr, 0, sizeof(arr));
    vector<int> arr(20);
    arr.assign(arr.size(), 0);
    for(int i=0;i<len;i++)
    {
        if(str[i] == '(')
            level++;
        else if(str[i] == ')')
            level--;
        else
            arr[level] += str[i] - '0';
    }
    //Debug
    for(auto i=0;i<20;i++)
        cout<<arr[i]<<" ";

    cout<<arr[k]<<"\n";     //answer
}
int main()
{
    int t;
    cin>>t;
    //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (t--)
    {
        int k;
        cin>>k;
        string s;
        cin>>s;
        findSumTree(s, k);
    }
    return 0;
}