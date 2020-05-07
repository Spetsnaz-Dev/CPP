// Using recursion
int findHeight(TreeNode *root, int key, int &parent, int height)
    {
        if(!root)
            return 0;
        
        if(root->val == key)
            return height;
        
        parent = root->val;
        int l = findHeight(root->left, key, parent, height+1);
        if(l !=0)
            return l;
        
        parent = root->val;
        int r = findHeight(root->right, key, parent, height+1);
        return r;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        if(root->val == x or root->val == y)
            return 0;
        
        int parentX = -1, parentY = -1, heightX, heightY;
        
        heightX = findHeight(root, x, parentX, 0);
        heightY = findHeight(root, y, parentY, 0);
        
        if(heightX == heightY and parentX != parentY)
            return true;
        else
            return false;
    }

    // Using Level Order
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root)
            return 0;
        
        TreeNode *t =  new TreeNode(-1);
        TreeNode *parA = NULL, *parB = NULL;
        
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push(make_pair(root, t)); //dummy node
        pair<TreeNode*, TreeNode*> p;
        
        int level;
        while(!q.empty())
        {
            level = q.size();
            while(level--)
            {
                p = q.front();
                q.pop();
            
                if(p.first->val == x)
                    parA = p.second;
                if(p.first->val == y)
                    parB = p.second;
                if(p.first->left)
                    q.push(make_pair(p.first->left, p.first));  //make current node as parent then travel left
                if(p.first->right)
                    q.push(make_pair(p.first->right, p.first));
                
                if(parA and parB)
                    break;
            }
            if(parA and parB)
                return parA != parB;
            if((!parA and parB) or (parA and !parB))
                return false;
        }
        return false;
    }