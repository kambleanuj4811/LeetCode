class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int sz = 0;
        ListNode* temp = head;

        while(temp != NULL) {
            sz++;
            temp = temp->next;
        }

        // Delete first node
        if(sz == n) {
            return head->next;
        }

        ListNode* prev = head;

        for(int i = 1; i < sz - n; i++) {
            prev = prev->next;
        }

        prev->next = prev->next->next;

        return head;
    }
};