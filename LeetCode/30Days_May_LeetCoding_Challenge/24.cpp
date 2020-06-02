
static int speedUp = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    TreeNode *buildBST(TreeNode* root, int ele)
    {
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
            root = buildBST(root, x);
        
        return root;
    }
};