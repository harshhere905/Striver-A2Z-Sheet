/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        vector<int> arr;
        while (temp != nullptr) {
            arr.push_back(temp->val);
            temp=temp->next;
        }
        for (int i = 0; i + k <= arr.size(); i += k) { 
              reverse(arr.begin() + i, arr.begin() + i + k);
          }
        ListNode* sample = head;
        int j = 0;
        while (sample != nullptr) {
            sample->val = arr[j++];
            sample = sample->next;
        }

        return head;
    }
};