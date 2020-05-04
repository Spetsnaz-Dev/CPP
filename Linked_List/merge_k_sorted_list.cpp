// https://leetcode.com/problems/merge-k-sorted-lists/

ListNode* mergeKLists(vector<ListNode*>& lists) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=0; i<lists.size(); i++){
            ListNode *ptr = lists[i];
            while(ptr != NULL){
                pq.push(ptr->val);
                ptr = ptr->next;
            }
        }
        ListNode *head = NULL, *temp;
        int curr;
        while(!pq.empty()){
            curr = pq.top();
            ListNode *t = new ListNode(curr);
            
            if(!head){
                head = t;
                temp = head;
            }
            else {
                temp->next = t;
                temp = temp->next;
            }
            pq.pop();
        }
        return head;
    }