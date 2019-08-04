//Find the mirror of a given BT
//Iterative
void mirror(Node* node) 
{
    if(!node)
        return;
    queue<Node *> q;
    q.push(node);
    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        Node *t = temp->left;
        temp->left = temp->right;
        temp->right = t;
        
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
}

//Recursive
void mirror(Node *node)
{
    if(!node)
        return;
    mirror(node->left);
    mirror(node->right);

    Node *temp = node->left;
    node->left = node->right;
    node->right = temp;
}