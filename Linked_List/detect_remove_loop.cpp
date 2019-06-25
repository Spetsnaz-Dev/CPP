//Detect and Remove loop from a Linked List
#include<iostream>
using namespace std;

struct node {
    int data;
    node *next;
};
void printLL(node *curr) {
    while (curr)
    {
        cout<<curr->data<<" -> ";
        curr= curr->next;
    }
    cout<<"\n";
}
node *newnode(int data) {
    node *new_node= new node();
    new_node->data= data;
    new_node->next= NULL;
    return new_node;
}
void detectAndRemoveLoop(node *head) {
    if(head== NULL)
        return ;

    node *sptr= head, *fptr= head;

    // sptr= sptr->next;
    // fptr= fptr->next->next;
    while(fptr && fptr->next) {
        if(sptr== fptr)
            break;
        sptr= sptr->next;
        fptr= fptr->next->next;
    }
    if (sptr == fptr)
    {
        sptr= head;
        while(sptr->next != fptr->next) {
        sptr= sptr->next;
        fptr= fptr->next;
        }
    fptr->next= NULL;
    }
}

int main() {
    node *head = newnode(50); 
    head->next = head; 
    head->next = newnode(20); 
    head->next->next = newnode(15); 
    head->next->next->next = newnode(4); 
    head->next->next->next->next = newnode(10); 
  
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next; 
  
    detectAndRemoveLoop(head); 

    cout<<"Final LL is - \n";
    printLL(head);

    return 0;
}