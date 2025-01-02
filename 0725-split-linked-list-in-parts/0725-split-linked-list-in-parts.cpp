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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* curr=head;
        int len=0;
        while(curr!=nullptr){
           len++;
           curr=curr->next;
        }
        int require_buckets=len/k;
        int extra_buckets=len%k;
        vector<ListNode*>res(k,NULL);
        curr=head;
        ListNode* prev=NULL;
        for(int i=0;i<k;i++){
            res[i]=curr;
            for(int cnt=1;cnt<=require_buckets+(extra_buckets>0?1:0);cnt++){
            prev=curr;
            curr=curr->next;
            }
            if(prev!=NULL)
               prev->next=NULL;
            extra_buckets--;
        }
      return res;
    }
};