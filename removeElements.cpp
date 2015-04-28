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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return head;
        ListNode *pre=new ListNode(0);
        ListNode *cur=head;
        pre->next=cur;
        ListNode *res=pre;
        while(cur){
            if(cur->val==val){
                cur=cur->next;
                pre->next=cur;
            }
            else{
                cur=cur->next;
                pre=pre->next;
            }
        }
        return res->next;
        
    }
};