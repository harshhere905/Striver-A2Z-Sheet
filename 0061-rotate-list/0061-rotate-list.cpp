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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0){
            return head;
        }
        ListNode* temp=head->next;
        ListNode* last=head;
        int cnt=1;
        while(last->next!=NULL){
            cnt++;
            last=last->next;
        }
        k = k % cnt; 
        if (k == 0) return head;
        int shifts=cnt-k;
        while(shifts){
            last->next=head;
            last=last->next;
            last->next=NULL;
            head=temp;
            temp=temp->next;
            shifts--;
        }
        return head;
    }
};