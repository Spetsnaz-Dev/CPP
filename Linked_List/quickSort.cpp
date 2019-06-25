// Quick Sort on Singly Linked List
#include<iostream>
using namespace std;

struct node {
    int data;
    node *next;
};
void push(struct node** head_ref, int new_data) 
{ 
    /* allocate node */
    struct node* new_node = new node(); 
  
    /* put in the data  */
    new_node->data  = new_data; 
  
    /* link the old list off the new node */
    new_node->next = (*head_ref); 
  
    /* move the head to point to the new node */
    (*head_ref)    = new_node; 
} 
  
void printLL(node *curr) {
    while (curr)
    {
        cout<<curr->data<<" -> ";
        curr= curr->next;
    }
    cout<<"\n";
}
node *getTail(node *curr) {
    while(curr && curr->next)
        curr= curr->next;
    return curr;
}
//Partition Function
node *partition(node *head, node *end, node **newHead, node **newTail) {
    node *pivot= end;
    node *prev= NULL, *curr= head, *tail= pivot;
    
    while (curr != pivot) {
        if(curr->data <= pivot->data) {
            if(*newHead == NULL)
                *newHead = curr;
            prev= curr;
            curr= curr->next;
        }
        else {
            if(prev)
                prev->next = curr->next;
            node *temp= curr->next;
            curr->next= NULL;
            tail->next= curr;
            tail= curr;
            curr= temp;
        }
    }
        if(*newHead== NULL)
            *newHead= pivot;
        *newTail= tail;
    return pivot;
}
//Quick Sort Function
node *qSortLL(node *head, node *tail) {
    if(!head || head == tail)
        return head;
    
    node *prev= NULL, *curr=head, *newHead=NULL, *newTail= NULL;
    node *pivot = partition(head, tail, &newHead, &newTail);

    if(newHead != pivot) {
        node *temp = newHead;
        while(temp->next != pivot)
            temp=temp->next;
        temp->next= NULL;

        newHead= qSortLL(newHead, temp);
        temp = getTail(newHead);
        temp->next= pivot;
    }
    pivot->next= qSortLL(pivot->next, newTail);

    return newHead;
}

void quickSort(node **head) {
    *head = qSortLL(*head, getTail(*head));
}
int main() 
{ 
    struct node *head = NULL; 
    push(&head, 5); 
    push(&head, 20); 
    push(&head, 4); 
    push(&head, 3); 
    push(&head, 30); 
  
    cout << "Linked List before sorting \n"; 
    printLL(head); 
  
    quickSort(&head); 
  
    cout << "Linked List after sorting \n"; 
    printLL(head); 
  
    return 0; 
}