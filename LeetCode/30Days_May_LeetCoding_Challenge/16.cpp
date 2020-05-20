// Odd Even Linked List
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head)
            return head;
        
        ListNode *odd = head, *even = head->next, *evenHead = even;

        while(even and even->next)
        {
            cout<<even->val<<" ";
            
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};