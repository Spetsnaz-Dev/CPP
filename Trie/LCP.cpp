#include<bits/stdc++.h>
using namespace std;
struct TrieNode {
    TrieNode *child[26];
    char val;   
    int wordCount = 0;
};
TrieNode *getNode() {
    TrieNode *ptr = new TrieNode;
    for (int i = 0; i < 26; i++) 
        ptr->child[i] = NULL; 
    
    return ptr; 
}
void insert(TrieNode *root, string key) {
    int len = key.length;
    int idx;

    TrieNode *p = new TrieNode;
    for(int i = 0; i< len; i++){
        idx = key[i] - 'a';
        if(!p->child[idx])
            p->child[idx] = getNode();
        p = p->child[idx];
    }
    p->wordCount++;
}
TrieNode *constructTrie(string s, int n, TrieNode *root) {
    for (int i = 0; i < n; i++) 
        insert (root, s[i]); 
    return; 
}
string longestCommonPrefix(string s, int n)
{
    TrieNode *root = getNode(); 
    constructTrie(s, n, root);
}
int main() {
    int tc;
    cin>>tc;
    int n;
    cin>>n;
    string s[n];

    for(int i=0;i<n;i++)
        cin>>s[i];
    string ans = longestCommonPrefix(s, n);

    if(ans.length)
        cout<<ans<<"\n";
    else
        cout<<"-1\n";

    return 0;
}