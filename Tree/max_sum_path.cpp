// Sum of the Longest Bloodline of a Tree (Sum of nodes on the longest path from root to leaf node)
void findSum(Node *root, vector<int> &v, int &count, int i, int x)
{
    if(!root->left && !root->right && count<=i){
        if(count < i)
            v.clear();
        v.push_back(x+root->data);
        count = i;
        return;
    }
    if(root->left)
        findSum(root->left, v, count, i+1, x+root->data);
    if(root->right)
        findSum(root->right, v, count, i+1, x+root->data);
}
int sumOfLongRootToLeafPath(Node* root)
{
    if(!root)
        return 0;
    int count = 0;
    vector<int> v;
    findSum(root, v, count, 1, 0);
    int res = INT_MIN;
    
    for(int i = 0; i < v.size(); i++){
        if(v[i] > res)
            res = v[i];
    }
    return res;
}


//Method 2
int heighttree(Node* root)
{
if(!root)
return 0;

return 1+std::max(heighttree(root->left),heighttree(root->right));
}
int pathsum(Node* root,int height)
{
if(height!=0 and !root)
{
return INT_MIN;
}

if(height==0 and !root)
{
return 0;
}

if(root)
return root->data + std::max(pathsum(root->left,height-1),pathsum(root->right,height-1));
}
int sumOfLongRootToLeafPath(Node* root)
{
int height=heighttree(root);
return pathsum(root,height);
}