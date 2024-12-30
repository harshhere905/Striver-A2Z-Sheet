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
        int total=0;
        while(temp!=nullptr){
            total++;
            if(total==k){
                p1=temp;
            }
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
       swap(p1->val,p2->val);
        return head;
    }
};