class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode dummy(0);
        ListNode* ans = &dummy;

        ListNode* i = list1;
        ListNode* j = list2;

        while (i != NULL && j != NULL) {

            if (i->val <= j->val) {
                ans->next = i;
                i = i->next;
            }
            else {
                ans->next = j;
                j = j->next;
            }

            ans = ans->next;
        }

        if (i != NULL) {
            ans->next = i;
        }
        else {
            ans->next = j;
        }

        return dummy.next;
    }
};