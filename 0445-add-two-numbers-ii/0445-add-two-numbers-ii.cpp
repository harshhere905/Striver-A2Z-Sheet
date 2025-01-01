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
    ListNode* reverse(ListNode* head){
        if(!head || head->next==nullptr){
            return head;
        }
        ListNode* last= reverse(head->next);
        head->next->next = head;
        head->next=NULL;
        return last;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverse(l1);
        l2=reverse(l2);
        int sum=0;
        int carry=0;
        ListNode* ans = new ListNode();
        while(l1!=NULL || l2!=NULL){
            if(l1){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2=l2->next;
            }
            ans->val=sum%10;
            carry=sum/10;
            ListNode* newnode = new ListNode(carry);
            newnode->next=ans;
            ans=newnode;
            sum=carry;
        }
        return (carry==0) ? ans->next : ans;
    }
};