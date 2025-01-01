class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* lessDummy = new ListNode(0);
        ListNode* highDummy = new ListNode(0);
        ListNode* less = lessDummy;
        ListNode* high = highDummy;
        while (head != nullptr) {
            if (head->val < x) {
                less->next = head;
                less = less->next;
            } else {
                high->next = head;
                high = high->next;
            }
            head = head->next;
        }
        less->next = highDummy->next;
        high->next = nullptr;
        ListNode* newHead = lessDummy->next;
        delete lessDummy;
        delete highDummy;

        return newHead;
    }
};
