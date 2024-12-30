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
    ListNode* swapPairs(ListNode* head) {
        if(!head || head->next==NULL){
            return head;
        }
        ListNode* dummy= new ListNode(0);
        dummy->next=head;
        ListNode* prev=dummy;
        ListNode* first;
        ListNode* second;
        while(prev->next && prev->next->next){
            first=prev->next;
            second=prev->next->next;
            first->next=second->next;
            second->next=first;
            prev->next=second;
            prev=first;
        }
        return dummy->next;
    }
};