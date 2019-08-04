//Right to left
Node *convertToDLL(Node *root,Node **head)
{
    if(!root)
        return NULL;
    
    if(!root->left && !root->right)
    {
        root->right = *head;
        if((*head) != NULL)
            (*head)->left = root;
        *head = root;
        return NULL;
    }
    root->right = convertToDLL(root->right, head);
    root->left = convertToDLL(root->left, head);
}
//Method 2
//Left to right
Node *convertToDLL(Node *root,Node **head)
{
    //*head=NULL;
    if(root==NULL)
        return NULL;
    static Node* prev=NULL;
    if(!root->left&&!root->right){
        if(*head==NULL)
            *head=root;
        else{
            root->left=prev;
            prev->right=root;
        }
        prev=root;
        return NULL;
    }
    root->left= convertToDLL(root->left,head);
    root->right= convertToDLL(root->right,head);
    
    return *head;
}