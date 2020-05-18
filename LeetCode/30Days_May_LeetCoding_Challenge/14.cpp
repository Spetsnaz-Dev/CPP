// Implement Trie (Prefix Tree)
class Trie {
public:
    struct Trienode
    {
        char data;
        int wc;
        bool end;
        Trienode *child[26];
    };
    
    /** Initialize your data structure here. */
    Trienode *root = new Trienode();
    Trie() {
        for(int i=0; i<26; i++)
            root->child[i] = NULL;
        root->data = '*';
        root->wc = 0;
        root->end = 0;
    }
    Trienode *getNode(char c)
    {
        Trienode *newnode = new Trienode();
        newnode->data = c;
        for(int i=0; i<26; i++)
            newnode->child[i] = NULL;
        newnode->wc = 0;
        newnode->end = 0;
        return newnode;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        
        Trienode *curr = root;
        int n = word.size(), c = 0;
        
        for(int i=0; i<n; i++)
        {
            c = word[i] - 'a';
            if(curr->child[c] == NULL)
                curr->child[c] = getNode(word[i]);
                
            curr->child[c]->wc += 1;
            if(i == n-1)
                curr->child[c]->end = 1;
            curr = curr->child[c];
        }
        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trienode *curr = root;
        int n = word.size(), c = 0;
        
        for(int i=0; i<n; i++)
        {
            c = word[i] - 'a';
            if(curr->child[c] == NULL or curr->child[c]->wc == 0)
                return false;
            
            if(i == n-1)
                if(curr->child[c]->end == 0)
                    return false;
            curr = curr->child[c];
        }
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        Trienode *curr = root;
        int n = word.size();
        
        for(int i=0; i<n; i++)
        {
            int c = word[i] - 'a';
            if(curr->child[c] == NULL or curr->child[c]->wc == 0)
                return false;

            curr = curr->child[c];
        }
        return true;
    }
};

static auto fastio = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();