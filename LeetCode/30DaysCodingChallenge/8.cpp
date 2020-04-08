/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // if(!head)
        //     return head;
        
        ListNode *fptr, *sptr;
        sptr = fptr = head;
        while(fptr->next and sptr->next){
            sptr = sptr->next;
            fptr = fptr->next;
            if(fptr->next)
                fptr = fptr->next;
        }
        return sptr;
    }
};