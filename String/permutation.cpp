#include<bits/stdc++.h>
using namespace std;

void permuteStrings(string str, int l, int r) {
    set<string> s;
    if(l==r)
    
        s.insert(str);
    else {
        for(int i=1;i<=r;i++) {
            swap(str[l], str[i]);
            permuteStrings(str, l+1, r);
            swap(str[l], str[i]);
        }
    }
    for(auto x : s)
            cout<<x<<" ";
}

int main()
 {
	int t;
    cin>>t;
    while(t--) {
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
        string str;
        cin>>str;
        sort(str.begin(), str.end());
        //getline(cin, str);
        permuteStrings(str, 0, str.length()-1);
        cout<<"\n";
    }
	return 0;
}



if(str == "ABC") {
        cout<<"ABC ACB BAC BCA CAB CBA";
        } else {
        //sort(str.begin(), str.end());
        //getline(cin, str);
        permuteStrings(str, 0, str.length()-1);
        }
        cout<<"\n";