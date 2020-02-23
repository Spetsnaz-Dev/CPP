// Largest number formed from an array of numbers
#include<bits/stdc++.h>
using namespace std;

bool compare(string s1, string s2){
    return  (s1+s2)>(s2+s1);
}
void findLargestNumber(vector<string> arr)
{
    sort(arr.begin(), arr.end(), compare); 
    //string res = arr[0];
    for(int i = 0; i < arr.size(); i++){
        cout<<arr[i];
    }
    cout<<"\n";
}
int main()
 {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];

        findLargestNumber(arr);
        }
	return 0;
}