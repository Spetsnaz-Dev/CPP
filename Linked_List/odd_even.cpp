//Segregate even and odd nodes in a Linked List
#include<iostream>
using namespace std;

struct node {
    int data;
    node *next;
};
void push(struct node** head_ref, int new_data) 
{ 
    struct node* new_node = new node(); 
    new_node->data  = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref)    = new_node; 
} 
void printLL(node *curr) {
    while (curr)
    {
        cout<<curr->data<<" ";
        curr= curr->next;
    }
    cout<<"\n";
}
void OddEven(node **head) {
    node *evenHead, *oddHead, *lastEven, *lastOdd;
    evenHead= oddHead= lastEven= lastOdd = NULL;

    node *curr= *head;
    while (curr != NULL)
    {
        if(!(curr->data) & 1) {         //check Even 
            if(evenHead == NULL)
                evenHead= lastEven= curr;
            lastEven->next= curr;
            lastEven= curr;
        }
        else {                          //if current is Odd
            if(oddHead == NULL)
                oddHead= lastOdd= curr;
            lastOdd->next= curr;
            lastOdd= curr;
        }
        curr= curr->next;
    }
    if(evenHead == NULL || oddHead == NULL)
        return ;
    lastEven->next= oddHead;
    lastOdd->next= NULL;
    // evenHead != NULL ? *head= evenHead : *head= oddHead;
    // oddHead ? lastEven->next= oddHead : lastEven->next= NULL;
    
    // if(lastOdd != NULL)
    //     lastOdd->next= NULL;
    *head = evenHead;
}
int main() 
{ 
    struct node *head = NULL; 
    push(&head, 5); 
    push(&head, 9); 
    push(&head, 4); 
    push(&head, 3); 
    push(&head, 7); 
    push(&head, 1);
    push(&head, 8);  
  
    cout << "Linked List before segregation \n"; 
    printLL(head); 
  
    OddEven(&head); 
  
    cout << "Linked List after segregation \n"; 
    printLL(head); 
  
    return 0; 
}