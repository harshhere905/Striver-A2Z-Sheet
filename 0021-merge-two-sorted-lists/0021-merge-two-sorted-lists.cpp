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
    ListNode* merge(ListNode* ll1,ListNode*ll2){
        ListNode* dummy = new ListNode(-1);
        ListNode* temp=dummy;
        while(ll1 && ll2){
            if(ll1->val<ll2->val){
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       return merge(list1,list2);
    }
};