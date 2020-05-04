#include "bits/stdc++.h"
using namespace std;
int lengthOfLongestSubstring(string str)        // Hashing
{
    if(str.size() == 0)
        return 0;

    unordered_map<char,int> m1;
	int ans=INT_MIN;
	int i=0;
	int j=0;
	int x=0;
	while(i<str.length())
	{
	    if(m1.find(str[i])==m1.end())
	    {
	        m1[str[i]]++;
	        ++x;
	        ans=max(ans,x);
	        i++;
	    }
	    else{
	    m1.erase(str[j]);j++;}
	}
    return ans;
}
// int lengthOfLongestSubstring(string str)     // Sliding Window Technique
// {
//     int visited[128] = {0}, start = 0, end = 0, curr = 0, size = 0;
//     int ele;
//     while (end < str.size()){
//         // ele = str[end] - 'a';   // Will not work if string has space int it
//         if(visited[str[end]] == 0){
//             visited[str[end]]++;
//             end++;
//             size = max(size, end-start);
//         } else {
//             visited[str[start]]--;
//             start++;
//         }
//     }
//     return size;
// }
int main()
{
    string s;
    cin>>s;
    cout<<lengthOfLongestSubstring<<"\n";

    return 0;
}