
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            }
            else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if (l1 != NULL) {
            curr->next = l1;
        }
        if (l2 != NULL) {
            curr->next = l2;
        }
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return NULL;
        }
        ListNode* result = lists[0];
        for (int i = 1; i < lists.size(); i++) {
            result = mergeTwoLists(result, lists[i]);
        }
        return result;
    }
};
