//Delete Nodes whose val is greater than K
Node* deleteNode(Node* root, int key)
{
    if(!root)
        return root;
    root->left = deleteNode(root->left, key);
    root->right = deleteNode(root->right, key);
    
    if(root->data >= key)
    {
        //delete
        if(!root->left && !root->right)
        {
            delete root;
            return NULL;
        }
        else if(!root->left)
        {
            Node *t = root->right;
            delete root;
            return t;
        }
        else if(!root->right)
        {
            Node *t = root->left;
            delete root;
            return t;
        }
        else {
            Node *t = root;
            delete root->right;
            return t;
        }
    }
    return root;
}
