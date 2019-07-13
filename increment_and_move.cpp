#include<bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *next, *prev;
};
void append(node **head, int data) {
    //add node at the end
    node *new_node = new node();
    new_node->data  = data;
    new_node->next= NULL;

    if(*head == NULL)
        *head= new_node;
    node *temp = *head;
    while(temp->next)
        temp= temp->next;
    temp->next= new_node;
    new_node->prev= temp;
    new_node->prev->next = new_node;
}
node *getTail(node *head) {
    while(head->next) 
        head= head->next;
    return head;
}
node *incrementAndMove(node **head, int n) {
    if(*head==NULL || n==2)
        return *head;
    node *prev_curr, *curr, *next_curr;
    prev_curr = *head;
    curr = prev_curr->next;
    next_curr = curr->next;

    node *tail = getTail(*head);

    while(curr->next && n--) {
        if(prev_curr->data == curr->data && next_curr->data == 100) {
            prev_curr->data = 100;
            curr->data = curr->data + floor(0.1*(curr->data));

            if(prev_curr == *head)
                *head = curr;

            //node *temp = curr;
            prev_curr->prev->next = curr;
            curr->prev = prev_curr->prev;
            prev_curr->next = NULL;
            prev_curr->prev = tail;
            tail->next = prev_curr;
            tail = tail->next;
            curr->next = next_curr->next;
            next_curr->next->prev = curr;
            next_curr->next = NULL;
            tail->next = next_curr;
            next_curr->prev = tail;
            tail = tail->next;
        }
        prev_curr = curr;
        curr = curr->next;
        next_curr = curr->next;
    }
    return *head;
}
void printLL(node *curr) {
    while (curr)
    {
        cout<<curr->data<<" -> ";
        curr= curr->next;
    }
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int data;
        node *head = NULL;
        for(int i=0;i<n;i++) {
            cin>>data;
            append(&head, data);
        }
        node *modified = incrementAndMove(&head, n);
        printLL(modified);
    }
    return 0;
}