#include "bits/stdc++.h"
using namespace std;

void findNums(vector<vector<int>> &res, string s)
{
    vector<int> v;
    int i = 0, n = 0;
    while(i < s.size())
    {
        if(s[i] == ','){
            v.push_back(n);
            n = 0;
            i++;
        }
        else if(s[i] == ';'){
            i += 3;
            v.push_back(n);
            res.push_back(v);
            v.clear();
            n = 0;
        }
        else{
            n = n*10 + (s[i] - '0');
            i++;
        }
    }
    v.push_back(n);
    res.push_back(v);
}
int main()
{
    string s;
    cin>>s;
    vector<vector<int>> arr;
    findNums(arr, s);

    vector<int> res;
    for(int i=0; i<arr.size(); i++){
        int sum = 0;
        for(int j : arr[i])
            sum += j;
        res.push_back(sum);
    }
    
    // find digital roots now
    int count = 0;
    for(int i=0; i<res.size(); i++){
        int curr = res[i], sum = res[i];
        cout<<curr<<" ";
        while (1)
        {
            curr = sum;
            sum = 0;
            while(curr)
            {
                sum += curr % 10;
                curr /= 10;
            }
            if(sum < 10)
                break;
        }
        if(sum & 1)
            count++;
    }
    cout<<count<<"\n";
}

// 1,2,3,4,5;;;4,6,9;;;8,9,6,5;;;9,87,54