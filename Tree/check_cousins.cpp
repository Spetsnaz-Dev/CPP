#include <bits/stdc++.h> 
using namespace std; 

struct Node { 0
    int data; 
    struct Node *left, *right; 
}; 
struct Node* newNode(int item) 
{ 
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
bool ifCousin(Node *root,Node *a,Node *b)
{
    if(root == NULL)
        return 0;
    queue<pair<Node*, Node*>> q;
    Node *t = newNode(-1);
    q.push(make_pair(root, t));
    Node *parentA = NULL, *parentB = NULL;
    pair<Node*, Node*> p;
    while(!q.empty())
    {
        int size = q.size();
        while(size--)
        {
        p = q.front();
        q.pop();
        
        if(p.first->data == a->data)
            parentA = p.second;
        if(p.first->data == b->data)
            parentB = p.second;
        if(p.first->left)
            q.push(make_pair(p.first->left, p.first));
        if(p.first->right)
            q.push(make_pair(p.first->right, p.first));
            
        if(parentA && parentB)
            break;
        }
        if(parentA && parentB)
            return parentA != parentB;
        if((!parentA&&parentB) || (!parentB&&parentA))
            return 0;
    }
    return 0;
}
int main() 
{ 
    /* 
            1  
           /  \  
          2    3 
         / \  / \ 
        4   5 6  7 
             \ \ 
             15 8 
    */
  
    struct Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->left->right->right = newNode(15); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
  
    struct Node *Node1, *Node2; 
    Node1 = root->left->left; 
    Node2 = root->right->right; 
  
    ifCousin(root, Node1, Node2) ? puts("Yes") : puts("No"); 
  
    return 0; 
} 