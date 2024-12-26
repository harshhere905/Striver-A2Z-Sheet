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
    ListNode* deleteMiddle(ListNode* head) {
        int size=1;
        ListNode* temp=head;
        while(temp->next){
            temp=temp->next;
            size++;
        }
        if(size==1){
            return nullptr;
        }
        if(size==2){
            head->next=nullptr;
            return head;
        }
        int index=ceil(size/2);
        ListNode* temp2=head;
        for(int i=0;i<index-1;i++){
            temp2=temp2->next;
        }
        ListNode* delete_node=temp2->next;
        temp2->next=temp2->next->next;
        delete delete_node;
        return head;
    }
};