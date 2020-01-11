bool callingWith(Node *root, int node, vector<int> &v)
{
    if(root==NULL)
        return 0;
    
    v.push_back(root->data);
    
    if(root->data == node)
        return 1;
    
    if(callingWith(root->left, node, v) || callingWith(root->right, node, v))
        return 1;
    
    v.pop_back();
    return 0;
}
int kthAncestor(Node *root, int k, int node)
{
    vector<int> v;
    v.clear();
    callingWith(root, node, v);
    if(k>v.size()-1 || k<=0)
        return -1;
    else
        return v[v.size()-1-k];
}