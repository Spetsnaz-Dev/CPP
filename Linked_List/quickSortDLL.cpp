//Quick Sort on Doubly Linked List
#include<iostream>
using namespace std;

struct node {
    int data;
    node *next, *prev;
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
void swap(int *a, int *b) {
    int temp = *a;
    *a= *b;
    *b= temp;
}
node *partitionDLL(node *low, node *high) {
    int x= high->data;
    node *i= low->prev;
    node *j;
    for(j= low; j != high; j= j->next) {
        if(j->data <= x) {
            i= (i==NULL) ? low : i->next;
            swap(&(i->data), &(j->data));
        }
    }
    i = (i==NULL) ? low : i->next;
    swap(&(i->data), &(high->data));

    return i;
}
void quickSortDLL(node *low, node *high) {
    if(low != high && low != NULL && high != NULL) {
        node *pivot= partitionDLL(low, high);
        quickSortDLL(low, pivot->prev);
        quickSortDLL(pivot->next, high);
    }
}
void quickSort(node *head) {
    quickSortDLL(head, getTail(head));
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
  
    quickSort(head); 
  
    cout << "Linked List after sorting \n"; 
    printLL(head); 
  
    return 0; 
}