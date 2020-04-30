    int findMax(TreeNode* root, int &res) 
    { 
        if (root == NULL) 
            return 0; 

        int l = max(0, findMax(root->left,res)); 

        int r = max(0, findMax(root->right,res)); 

        res = max(res, l+r+root->val); 
  
        return root->val + max(l, r); 
    } 
    int maxPathSum(TreeNode* root) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int res = INT_MIN;
        
        findMax(root, res);
        
        return res;
    }