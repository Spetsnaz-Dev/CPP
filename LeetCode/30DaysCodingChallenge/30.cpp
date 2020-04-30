bool call(TreeNode* root, vector<int> arr, int i, int n) {
        if(!root)
            return n == 0;
        
        if(!root->left and !root->right and arr[i] == root->val and (i == n))
            return 1;
        
        return ((i<n) and arr[i]==root->val) and 
                (call(root->left, arr, i+1, n) or 
                call(root->right, arr, i+1, n));
    }
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        
        if(root->val != arr[0])
            return false;

        bool ans = call(root, arr, i, n-1);

        return ans;
    }