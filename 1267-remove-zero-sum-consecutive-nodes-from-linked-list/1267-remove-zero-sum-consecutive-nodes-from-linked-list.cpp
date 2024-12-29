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
    ListNode* removeZeroSumSublists(ListNode* head) {
      int prevsum=0;
      unordered_map<int,ListNode*>mp;
      ListNode* dummy=new ListNode(0);
      mp[0]=dummy; 
      dummy->next=head;
      while(head!=nullptr){
        prevsum+=head->val;
        if(mp.find(prevsum)!=mp.end()){
           int psum=prevsum;
           ListNode* start=mp[prevsum];
           ListNode* temp=start;
           while(temp!=head){
            temp=temp->next;
            psum+=temp->val;
            if(temp!=head){
                mp.erase(psum);
            }
           }
           start->next=head->next;
        }
        else{
            mp[prevsum]=head;
        }
        head=head->next;
      }
      return dummy->next;
    }
};