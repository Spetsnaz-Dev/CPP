class Solution {
public:
    void inorder(TreeNode *root, int k, vector<int>& v, int count)
    {
        if(!root)
            return;
        inorder(root->left, k, v, count);
        v.push_back(root->val);
        ++count;
        if(count == k)
            return;
        inorder(root->right, k, v, count);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        
        inorder(root, k, v, 0);
        
        return v[k-1];
    }
};