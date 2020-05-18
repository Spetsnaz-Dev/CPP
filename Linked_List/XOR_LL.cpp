/*
Structure of linked list is as
struct Node
{
	int data;
	struct Node* npx; 
	
	Node(int x){
	    data = x;
	    npx = NULL;
	}
};

Utility function to get XOR of two Struct Node pointer
use this function to get XOR of two pointers 
struct Node* XOR (struct Node *a, struct Node *b)
{
	return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}
*/
void insert(struct Node **head, int data)
{
    Node *ptr = new Node(data);
    //ptr->data = data;
    ptr->npx = XOR(*head, NULL);
    
    if(*head != NULL)
    {
        Node *next = XOR((*head)->npx, NULL);
        (*head)->npx = XOR(next, ptr);
    }
    *head = ptr;
}

void printList (struct Node *head)
{
    Node *prev = NULL, *curr = head, *next;
    while(curr)
    {
        cout<<curr->data<<" ";
        next = XOR(curr->npx, prev);
        
        prev = curr;
        curr = next;
    }
    cout<<"\n";
    curr = NULL;
    while(prev)
    {
        cout<<prev->data<<" ";
        next = XOR(prev->npx, curr);
        
        curr = prev;
        prev = next;
    }
    // cout<<"\n";
}