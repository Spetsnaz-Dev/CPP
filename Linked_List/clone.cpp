//Clone a linked list with next and arbit pointer
#include<iostream>
using namespace std;
struct node {
    int data;
    node *next, *arbit;
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
    new_node->next = new_node->arbit = NULL;
    return new_node;
}
node *clone(node *head) {
    if(!head)
        return head;
    node *temp, *curr= head;
    //create clone node
    while(curr) {
        temp = curr->next;
        curr->next= newnode(curr->data);
        curr->next->next= temp;
        curr= temp;
    }
    curr= head;
    //Set arbit pointer
    while(curr) {
        if(curr->next) {
            curr->next->arbit= curr->arbit->next;
            curr= curr->next->next;
        }
    }
    //Separate Original & New List
    node *original = head, *copy= head->next;
    temp= copy;
    while(original && copy) {
        original->next= original->next->next;
        copy->next= copy->next->next;

        original=original->next;
        copy= copy->next;
        //cout<<copy->data;
    }
    original->next= NULL;
    copy->next= NULL;
    return temp;
}
int main() {
    node *head = newnode(1); 
    head->next = newnode(2); 
    head->next->next = newnode(3); 
    head->next->next->next = newnode(4); 
    head->next->next->next->next = newnode(5); 
    head->next->next->next->next->next = newnode(8); 
    // 1's arbit points to 3 
    head->arbit = head->next->next; 
    // 2's arbit points to 1 
    head->next->arbit = head; 
    // 3's and 4's arbit points to 5 
    head->next->next->arbit = head->next->next->next->next; 
    head->next->next->next->arbit = head->next->next->next->next; 
    // 5's arbit points to 2 
    head->next->next->next->next->arbit = head->next; 
    head->next->next->next->next->next->arbit = head->next->next->next; 

    cout << "Original list : \n"; 
    printLL(head);

    node *new_list= clone(head); 

    cout<<"Final LL is - \n";
    printLL(new_list);

    return 0;
}