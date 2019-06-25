//Delete Operatons in Linked Lists
#include<iostream>
using namespace std;

struct node {
    int data;
    node *next;
};
void push(node **head, int data) {
    node *new_node = new node;
    new_node->data = data;
    new_node->next = *head;
    *head= new_node;
}
void printLL(node *curr) {
    while (curr)
    {
        cout<<curr->data<<" -> ";
        curr= curr->next;
    }
}
void del(node **head, int key) {
    node *temp = *head;
    if(temp == NULL)
        return ;
    
    node *prev;
    while(temp != NULL && temp->data != key) {
        prev= temp;
        temp= temp->next;
    }
    prev->next = temp->next;
    free(temp);
}

int main() {
    node *head = NULL;
    push(&head, 5);
    push(&head, 6);
    push(&head, 7);
    push(&head, 8);
    push(&head, 9);
    push(&head, 10);

    del(&head, 6);
    del(&head, 7);

    cout<<"Created LL is - \n";
    printLL(head);

    return 0;
}