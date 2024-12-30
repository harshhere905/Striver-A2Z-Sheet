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
    int pairSum(ListNode* head) {
        int n=0;
        ListNode* temp=head;
        while(temp!=nullptr){
            n++;
            temp=temp->next;
        }
        int range=(n/2)-1;
        unordered_map<int,int>mp;
        int cnt=0;
        ListNode* p1=head;
        ListNode* p2=head;
        while(p1!=nullptr){
           mp[cnt]=p1->val;
           cnt++;
           if(cnt>range){
            break;
           }
           p1=p1->next;
        }
        cnt=cnt-1;
        p2=p1->next;
        while(p2!=nullptr){
            mp[cnt]+=p2->val;
            cnt--;
            if(cnt<0){
                break;
            }
            p2=p2->next;
        }
        int maxi=INT_MIN;
        for(auto it:mp){
            maxi=max(maxi,it.second);
        }
        return maxi;
    }
};