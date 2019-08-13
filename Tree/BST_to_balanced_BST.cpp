void inorder(Node *root, vector<Node *> &v)
{
    if(!root)
        return;
    inorder(root->left, v);
    v.push_back(root);
    inorder(root->right, v);
}
Node *buildBST(vector<Node *> arr, int low, int high)
{
    if(low > high)
        return NULL;
        
    int mid = (low+high) >> 1;
    Node *node = arr[mid];
    node->left = buildBST(arr, low, mid-1);
    node->right = buildBST(arr, mid+1, high);
    
    return node;
}
Node* buildBalancedTree(Node* root)
{
    vector<Node *> v;
    v.clear();
    inorder(root, v);
    
    return buildBST(v, 0, v.size()-1);
}
