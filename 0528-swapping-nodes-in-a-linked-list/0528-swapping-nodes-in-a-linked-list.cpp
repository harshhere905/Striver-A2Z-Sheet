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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* p1=head;
        ListNode* p2=head;
        int cnt=0;
        int total=0;
        while(p1!=nullptr){
            cnt++;
            if(cnt==k){
                break;
            }
            p1=p1->next;
        }
        while(temp!=nullptr){
            total++;
            temp=temp->next;
        }
        int diff=(total-k)+1;
        while(p2!=nullptr){
            diff--;
            if(diff==0){
                break;
            }
            p2=p2->next;
        }
        int sample=0;
        sample=p1->val;
        p1->val=p2->val;
        p2->val=sample;
        return head;
    }
};