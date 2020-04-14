// Perform String Shifts
#include "bits/stdc++.h"
using namespace std;

string stringShift(string s, vector<vector<int>>& shift) { 
    // 0 - LEFT SHIFT   1 - RIGHT SHIFT
    int amount, direction;
    int len = s.size();
    for(int i=0; i<shift.size(); i++){
        direction = shift[i][0];
        amount = shift[i][1];

        switch(direction){
            case 0:
                reverse(s.begin(), s.begin()+amount);
                reverse(s.begin()+amount, s.end());
                reverse(s.begin(), s.end());
                // cout<<s<<"\n";
                break;
            case 1:
                reverse(s.begin(), s.end());
                reverse(s.begin(), s.begin()+amount);
                reverse(s.begin()+amount, s.end());
                // cout<<s<<"\n";
                break;
            }
        }
    return s;
}
int main()
{
    string s;
    cin>>s;

    int n;
    cin>>n;
    vector<vector<int> > v( n , vector<int> (2));

    int ele;
    for(int i=0; i<n; i++)
        for(int j=0; j<2; j++){
            cin>>ele;
            v[i].push_back(ele);
        }
    cout<<stringShift(s, v);
}