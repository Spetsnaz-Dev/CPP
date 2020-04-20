#include<iostream>
using namespace std;
struct Node{
 int data;
 Node* right;
 Node* left;
};
Node* newNode(int x)
{
    Node* ptr = (Node*)malloc(sizeof(Node*));
    ptr->data =x;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}
Node *buildBST(int arr[], int low, int high)
{
    int mid = (low+high)/2;
    Node *root = newNode(arr[mid]);
    buildBST(arr, low, mid-1);
    buildBST(arr, mid+1, high);

    return root;
}
void preorder(Node *root){
    if(!root)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main()
 {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Node *root = buildBST(arr, 0, n-1);
        
        preorder(root);
        cout<<"\n";
    }
	return 0;
}
//Method 2
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