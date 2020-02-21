#include<iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

void push(node **head, int data) {
    // node *ptr = *head;
    node *new_node = new node;
    new_node->data = data;
    new_node->next = *head;
    *head= new_node;
}
void append(node **head, int data) {
    //add at the end
    node *new_node = new node();
    new_node->data  = data;
    new_node->next= NULL;

    if(*head == NULL)
        *head= new_node;
    node *temp = *head;
    while(temp->next)
        temp= temp->next;
    temp->next= new_node;
}
void insertAfter(node *prev, int data) {
    if(prev == NULL) {
        cout<<"NULL prev pointer found \n";
        return ;
    }
    node *new_node= new node();
    node *temp = prev;
    new_node->data = data;
    new_node->next = temp->next;
    prev->next= new_node;
}
void printLL(node *curr) {
    while (curr)
    {
        cout<<curr->data<<" -> ";
        curr= curr->next;
    }
}

int main() {
    node *head = NULL;
    push(&head, 5);
    push(&head, 6);
    push(&head, 7);
    push(&head, 8);
    append(&head, 9);
    insertAfter(head->next->next->next, 10);

    cout<<"Created LL is - \n";
    printLL(head);

    return 0;
}