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
private:
    ListNode* findmid(ListNode* temp){
        ListNode* slow=temp;
        ListNode* fast=temp->next;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* ll1,ListNode* ll2){
        ListNode* dummy = new ListNode(-1);
        ListNode* temp=dummy;
        while(ll1 && ll2){
            if(ll1->val < ll2->val){
                temp->next=ll1;
                temp=ll1;
                ll1=ll1->next;
            }
            else{
                temp->next=ll2;
                temp=ll2;
                ll2=ll2->next;  
            }
        }
        if(ll1){
            temp->next=ll1;
        }
        else{
            temp->next=ll2;
        }
        return dummy->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* middle=findmid(head);
        ListNode* second_head=middle->next;
        middle->next=nullptr;
        ListNode* first_head=head;
        first_head=sortList(first_head);
        second_head=sortList(second_head);
        return merge(first_head,second_head);
    }
};