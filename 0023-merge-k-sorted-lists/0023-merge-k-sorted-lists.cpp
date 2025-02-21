class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr; 
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        vector<int> ans;
        for (int i = 0; i < lists.size(); i++) {
            ListNode* temp = lists[i];
            while (temp) {
                ans.push_back(temp->val);
                temp = temp->next;
            }
        }
        sort(ans.begin(), ans.end());
        for (int val : ans) {
            tail->next = new ListNode(val);
            tail = tail->next;
        }
        return dummy->next;
    }
};
