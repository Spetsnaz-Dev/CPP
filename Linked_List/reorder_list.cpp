#include<bits/stdc++.h>
void reorderList(Node* head) {
    if(!head or !head->next)
        return;
    
    vector<Node *> v;
    Node *curr = head;
    while(curr){
        v.push_back(curr);
        curr = curr->next;
    }
    
    int n = v.size(), i;
    curr = head;
    
    for(i=0; i<n/2; i++){
        if(i != 0){
            curr->next = v[i];
            curr = curr->next;
        }
        curr->next = v[n-i-1];
        curr = curr->next;
    }
    if(n%2 != 0){
        curr->next = v[i];
        curr = curr->next;
    }
    curr->next = NULL;
}

// Method 2---
// -> Split and Reverse the list from middle to last node
// -> Now, merge the 2 halves while picking elements alternatively from each half.