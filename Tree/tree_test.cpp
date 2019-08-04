//Given a target Node and K, print the Kth ancestor of the target node
#include <bits/stdc++.h> 
using namespace std; 
  
// Structure of Tree 
struct node { 
    node *left, *right; 
    int data; 
}; 
  
// To create a new node 
node* newNode(int data) 
{ 
    node* temp = new node; 
    temp->left = temp->right = NULL; 
    temp->data = data; 
    return temp; 
} 
  
// Function to find the path from 
// root to the target node 
void RootToNode(node* root, vector<int>& v) 
{ 
    if (root == NULL) 
        return; 
  
    // Add current node to the path 
    v.push_back(root->data);

    RootToNode(root->left, v);
    RootToNode(root->right, v);
} 
  
// Driver code 
int main() 
{ 
    struct node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 

    vector<int> v; 
    RootToNode(root, v); 
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    return 0;
} 