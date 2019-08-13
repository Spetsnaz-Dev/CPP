void topView(struct Node *root)
{
    if(!root)
        return;
    //int hd =0;
    map<int, int> mp;
    queue<pair<Node*, int>> q;
    pair<Node*, int> p;
    q.push(make_pair(root, 0));
    while(!q.empty())
    {
        p = q.front();
        Node *t = p.first;
        int val = p.second;
        q.pop();
        if(mp.find(val) == mp.end())
            mp[val] = t->data;
        if(t->left)
            q.push(make_pair(t->left, val-1));
        if(t->right)
            q.push(make_pair(t->right, val+1));
    }
    for(auto i =mp.begin();i!= mp.end();++i)
    {
        cout<<i->second<<" ";
    }
}
