void vertical(Node * root,int col,map<int,vector<int> >&m)
{
    queue<pair<Node *,int> >q;
    q.push(make_pair(root,0));
    while(!q.empty())
    {
        Node *fro=q.front().first;
        int col=q.front().second;
        m[col].push_back(fro->data);
        if(fro->left)
            q.push(make_pair(fro->left,col-1));
        if(fro->right)
            q.push(make_pair(fro->right,col+1));
        q.pop();
    }
}
void verticalOrder(Node *root)
{
    if(root==NULL)
        return;
    int col=0;
    map<int,vector<int> >m;
    vertical(root,col,m);
    for(auto it=m.begin();it!=m.end();++it)
    {
        for(int i=0;i<it->second.size();i++)
            cout<<m[it->first][i]<<" ";
    }
}