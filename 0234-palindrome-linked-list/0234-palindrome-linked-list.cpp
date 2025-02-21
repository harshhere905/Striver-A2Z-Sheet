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
    bool isPalindrome(ListNode* head) {
        vector<int>sample;
        ListNode* temp=head;
        while(temp!=nullptr){
            sample.push_back(temp->val);
            temp=temp->next;
        }
        reverse(sample.begin(),sample.end());
        ListNode* samp=head;
        for(int i=0;i<sample.size();i++){
            if(samp->val!=sample[i]){
                return false;
            }
            else{
                samp=samp->next;
            }
        }
        return true;
    }
};