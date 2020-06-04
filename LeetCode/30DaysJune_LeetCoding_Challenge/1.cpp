class Solution {
public:
    TreeNode* inOrder(TreeNode* root)
    {
        if(!root)
            return NULL;
        
        inOrder(root->left);
        inOrder(root->right);
        
        TreeNode* t = root->left;
        root->left = root->right;
        root->right = t;
        
        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
        return inOrder(root);
    }
};