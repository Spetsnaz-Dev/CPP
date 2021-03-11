//CODE TO Count_Number_Of_Strings_With_Given_Prefix
//Assumption: All characters are in lowercase
#include<iostream>
using namespace std;
//#define NULL 0

struct Trienode
{
    char data;
    int wc;  //wc:word_count
    Trienode *child[26];
};
Trienode nodepool[100000];  //Pool of 100K Trienodes
Trienode *root;    //Root of Trie
int poolcount;  //Always points to next free Trienode

void init() //Initializer function
{
    poolcount = 0;
    root = &nodepool[poolcount++];
    root->data = '/';
    for(register int i=0;i<26;++i)
        root->child[i] = NULL;
}

Trienode *getNode(char c)
{
    Trienode *newnode = &nodepool[poolcount++];
    newnode->data = c;
    for(register int i=0;i<26;++i)
        newnode->child[i] = NULL;
    newnode->wc=0;
    return newnode;
}

void insert(char *s)
{
    Trienode *curr = root;  
    int index;
    for(int i=0; s[i]!='\0'; ++i)
    {
        index = s[i]-'a';
        if(curr->child[index]==NULL)
            curr->child[index] = getNode(s[i]);
        curr->child[index]->wc += 1;
        curr = curr->child[index];
    }
}

bool search(char *s)
{
    Trienode *curr = root;
    int index;
    for(int i=0; s[i]!='\0'; ++i)
    {
        index = s[i]-'a';
        if(curr->child[index]==NULL || curr->child[index]->wc == 0)
            return false;
        curr = curr->child[index];
    }
    return true;
}

bool Triedelete(char *s)
{
    if(search(s))
    {
        Trienode *curr = root;
        int index;
        for(int i=0; s[i]!='\0'; ++i)
        {
            index = s[i]-'a';
            curr->child[index]->wc -=1;
            curr = curr->child[index];
        }
    }
}

int countPrefix(string s)
{
    Trienode *curr = root;
    int index;
    for(int i=0; s[i]!='\0'; ++i)
    {
        index = s[i]-'a';
        if(curr->child[index]==NULL || curr->child[index]->wc == 0)
            return 0;   //No string with given prefix is present
        curr = curr->child[index];
    }
    return curr->wc;
}

int main()
{
    init();
    char a[5] = {'a','r','m','y'};
    char b[5] = {'a','r','m'};
    char c[5] = {'a','r','m','s'};
    char d[5] = {'a','r','y'};
    char e[5] = {'a','m','y'};
    char f[5] = {'a','p','i'};


    insert(a);
    insert(b);
    insert(c);
    insert(d);
    insert(e);
    insert(f);

    //cout<<search(b)<<"\n";

    printf("No of strings with given prefix = %d\n",countPrefix("a"));
    printf("No of strings with given prefix = %d\n",countPrefix("ar"));
    printf("No of strings with given prefix = %d\n",countPrefix("arm"));
    printf("No of strings with given prefix = %d\n",countPrefix("army"));
    printf("No of strings with given prefix = %d\n",countPrefix("armi"));
    printf("No of strings with given prefix = %d\n",countPrefix("ary"));

    cout<<"Deletion...STARTED\n";
    Triedelete(a);
    Triedelete(d);
    cout<<"DONE...\n\n";


    printf("No of strings with given prefix = %d\n",countPrefix("a"));
    printf("No of strings with given prefix = %d\n",countPrefix("ar"));
    printf("No of strings with given prefix = %d\n",countPrefix("arm"));
    printf("No of strings with given prefix = %d\n",countPrefix("army"));
    printf("No of strings with given prefix = %d\n",countPrefix("armi"));
    printf("No of strings with given prefix = %d\n",countPrefix("ary"));

    return 0;
}


// Method 2 
struct TrieNode {
    TrieNode* children[26];
    bool is_end;
    int count;
    
    TrieNode() {
        memset(children, 0, sizeof(children));
        is_end = false;
        count = 0;
    }
};

class Solution {
public:
    int countSubstrings(string s, string t) {
        TrieNode* root = new TrieNode();
        int ret = 0;
        
        for(int i = 0; i < s.size(); i++) {
            insert(root, s, i, s.size());
        }
        
        for(int i = 0; i < t.size(); i++) {
            search(root, t, i, t.size(), 0, ret);
        }

        return ret;
    }

private:
    void insert(TrieNode* root, string word, int i, int len) {
        root->is_end = true;
        root->count += 1;
        
        if(i >= len) return;
        
        if(root->children[word[i]-'a'] == nullptr) {
            root->children[word[i]-'a'] = new TrieNode();
        }
        
        insert(root->children[word[i]-'a'], word, i+1, len);
    }
    
    void search(TrieNode* root, string word, int i, int len, int mismatches, int& ret) {
        if(mismatches > 1) return;
        
        if(mismatches == 1) {
            ret += root->count;
        }
        
        if(i >= len) return;
        
        for(int k = 0; k < 26; k++) {
            if(root->children[k]) {
                if(k == word[i]-'a') {
                    search(root->children[k], word, i+1, len, mismatches, ret);
                } else {
                    search(root->children[k], word, i+1, len, mismatches+1, ret);
                }
            }
        }
    }
};