/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev=new ListNode(-1);
        ListNode *cur=head;
        if(cur==NULL) return head;
        prev->next=cur;
        ListNode *nxt=head->next;
        while(nxt){
            cur->next=nxt->next;
            nxt->next=prev->next;
            prev->next=nxt;
            nxt=cur->next;
        }
        return prev->next;
    }
};