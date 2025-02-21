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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        set<int>st;
        ListNode* temp=head;
        while(temp!=nullptr){
            st.insert(temp->val);
            temp=temp->next;
        }
        ListNode* sample=head;
        ListNode* prev=nullptr;
        for(auto it:st){
           prev=sample;
           sample->val=it;
           sample=sample->next;
        }
        if (prev) prev->next = NULL;
        return head;

    }
};