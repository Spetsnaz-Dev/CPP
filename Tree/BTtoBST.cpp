//My Code
void storeInorder(Node *root, vector<int> &v)
{
    if(!root)
        return;
    storeInorder(root->left, v);
    v.push_back(root->data);
    storeInorder(root->right, v);
}
void buildBST(Node *root, vector<int> &v, int k)
{
    if(!root)
        return;
    buildBST(root->left, v, k);
    root->data = v[k++];
    buildBST(root->right, v, k);
}
Node *binaryTreeToBST (Node *root)
{
    vector<int> v;
    v.clear();
    
    storeInorder(root, v);
    
    sort(v.begin(), v.end());
    int i=0;
    buildBST(root, v, i);
    return root;
}

//Other Code
void inorder(vector<int> &in,Node* root)
{
    if(!root)
        return;
    inorder(in,root->left);
    in.push_back(root->data);
    inorder(in,root->right);
}
void bst(Node* root, vector<int> &in, int &i)
{
    if(!root)
    {
        //i++;
        return;
    }
    bst(root->left,in,i);
    root->data = in[i++];
    bst(root->right,in,i);
}
Node *binaryTreeToBST (Node *root)
{
    vector<int> in;
    inorder(in, root);
    sort(in.begin(), in.end());
    int i =0;
    bst(root,in,i);
    
    return root;
}
