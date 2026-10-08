class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* temp = &dummy;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        while (temp1 && temp2) {
            if (temp1->val < temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }

        // Attach whatever is left over
        if (temp1) temp->next = temp1;
        if (temp2) temp->next = temp2;

        return dummy.next;
    }
};