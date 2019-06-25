#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};
void printLL(Node *curr) {
    while (curr)
    {
        cout<<curr->data<<" ";
        curr= curr->next;
    }
    cout<<"\n";
}
void reverse(Node **head) {
    Node *prev, *curr, *next;
    curr = *head, prev= NULL;
    while(curr) {
        next = curr->next;
        curr->next = prev;
        prev= curr;
        curr= next;
    }
    *head = prev;
}
bool check_palindrome(Node *head1, Node *head2) {
    Node *temp1= head1, *temp2= head2;

    if(temp1 == NULL && temp2 == NULL)
        return 1;

    while(temp1 && temp2) {
        if(temp1->data != temp2->data)
            return 0;
        
        temp1= temp1->next;
        temp2= temp2->next;
    }
    return 1;
}
bool isPalindrome(Node *head) {
    Node *sptr, *fptr, *prev_of_sptr;
    sptr=fptr= head;
    while(fptr && fptr->next) {
        prev_of_sptr= sptr;
        sptr=sptr->next;
        fptr= fptr->next->next;
    }
    Node *mid_Node = NULL;
    if(fptr != NULL) {
        mid_Node= sptr;
        sptr= sptr->next;
    }
    Node *second_half= sptr;
    reverse(&second_half);
    int res= check_palindrome(head, second_half);
    reverse(&second_half);

    if(mid_Node != NULL) {
        prev_of_sptr->next= mid_Node;
        mid_Node->next= second_half;
    } else
    {
        prev_of_sptr->next = second_half;
    }
    //cout<<res;
    return res;
}
void push(struct Node** head_ref, int new_data) 
{ 
    /* allocate Node */
    struct Node* new_Node = new Node();
  
    /* put in the data  */
    new_Node->data  = new_data; 
  
    /* link the old list off the new Node */
    new_Node->next = (*head_ref); 
  
    /* move the head to pochar to the new Node */
    (*head_ref)    = new_Node; 
} 

int main() 
{ 
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int arr[n];
        struct Node* head = NULL; 
        int i; 
        for (i = 0; i < n; i++)  {
            cin>>arr[i];
            push(&head, arr[i]);
        }
        isPalindrome(head);
    }
    return 0; 
} 