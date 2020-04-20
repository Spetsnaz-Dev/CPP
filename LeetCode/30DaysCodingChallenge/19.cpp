TreeNode *buildBST(TreeNode* &root, int ele) {
        if(!root)
            return root = new TreeNode(ele);
        
        if(root->val > ele)
            root->left = buildBST(root->left, ele);
        else
            root->right = buildBST(root->right, ele);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        TreeNode *root = NULL;
        
        for(auto x : pre)
            buildBST(root, x);
        
        return root;
    }