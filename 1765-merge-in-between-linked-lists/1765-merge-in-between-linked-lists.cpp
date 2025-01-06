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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* prev=list1;
        int diff=(b-a)+1;
        while(prev && a>1){
            prev=prev->next;
            a--;
        }
        ListNode* last = prev->next;
        for (int i = 0; i < diff; i++) {
            last = last->next;
        }
        ListNode* last_list=list2;
        while(last_list->next!=nullptr){
            last_list=last_list->next;
        }
         prev->next = list2;
        last_list->next = last;
        return list1;
    }
};