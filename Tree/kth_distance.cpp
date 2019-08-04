//Print all nodes that are at distance k from root (root is considered at distance 0 from itself). 
void printKdistance(Node *root, int k)
{
if(root==NULL)
    return;

if(k==0)
{
    cout<<root->data<<" ";
    return ;
}
printKdistance(root->left,k-1);
printKdistance(root->right,k-1);
}