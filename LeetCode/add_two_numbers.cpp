class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *h1 = l1, *h2 = l2;
        ListNode *head = NULL, *prev = NULL, *ptr;
        int sum, carry = 0;
        while(h1 or h2){
            sum = (h1 ? h1->val : 0) + (h2 ? h2->val : 0) + carry;
            carry = sum > 9 ? 1 : 0 ;
            sum = sum % 10;
            ptr = new ListNode(sum);
            
            if(!head) {
                head = ptr;
                prev = head;
            }
            else {
                prev->next = ptr;
            }
            prev = ptr;
            
            h1 = h1 ? h1->next : 0;
            h2 = h2 ? h2->next : 0;
        }

        if(carry == 1){
            prev->next = new ListNode(carry);
        }
        return head;
    }
};