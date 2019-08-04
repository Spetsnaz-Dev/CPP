bool isIsomorphic(Node *r1,Node *r2)
{
if(r1==NULL && r2==NULL)
return true;
if(r1==NULL || r2==NULL)
return false;
return (r1->data==r2->data && ((isIsomorphic(r1->left,r2->right)&& 
        isIsomorphic(r1->right,r2->left))||(isIsomorphic(r1->left,r2->left)&& 
        isIsomorphic(r1->right,r2->right))));
}