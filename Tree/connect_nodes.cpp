//Connect Nodes at same level
void connect(Node *p)
{
    if(p== NULL)
        return;
    
    queue<Node *> q;
    q.push(p);
    Node *prev, *temp;
    while(!q.empty())
    {
        prev = q.front();
        cout<<prev->data<<" ";
        q.pop();
        if(q.size()>0)
        {
            temp = q.front();
            prev->nextRight = temp;
        } 
        else prev->nextRight = NULL;
        
        if(prev->left)
            q.push(prev->left);
        if(prev->right)
            q.push(prev->right);
    }
    cout<<"\n";
}
