void leftView(Node *root)
{
    if(!root)
        return;
    queue<Node *> q;
    q.push(root);
    while(!q.empty())
    {//Print the first Node in queue and remove the rest in each level
        cout<<q.front()->data<<" ";
        int size = q.size();
        while(size--)
        {
            Node *t = q.front();
            q.pop();
            if(t->left)
                q.push(t->left);
            if(t->right)
                q.push(t->right);
        }
    }
}