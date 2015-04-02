#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x),next(null){}
	
};

ListNode *addTwoNumbers(ListNode *l1, ListNode*l2){
	ListNode dumm(-1); 
	int carry = 0;
	ListNode *prev = &dummy;
	for(ListNode *pa = l1, *pb=l2; pa!=null || pb!=null;pa=pa==null?null:pa-next,pb=pb==null?null:pb->next,prev=prev->next){
		const int a=pa==null?0:pa->val;
		const int b=pb==null?0:pb->val;
		const int value= (a+b+carry)%10;
		carry = (a+b+carry)/10; 
		prev->nextew ListNode(value);
	} 
	if(carry>0){
		prev->next = new ListNode(carry); 
	return dummy;
	}
}

ListNode *reverseBetween(ListNode *head, int m, int n){
	ListNode dummy(-1);
	dummy.next = head;
	ListNode *prev = &dummy;
	for(int i=0;i<m-1;++i;)
	{
		prev=prev->next;
	} 
	ListNode* const head2 = prev;
	prev=head2->next;
	ListNode *cur = prev->next;
	for(int i=m;i<n;++i){
		prev->next=cur->next;
		cur->next = head2->next;
		head2->next = cur;
		cur = prev->next;
	}  
	return dummy.next;
}

int main(int argc, char *argv[]) {
	
}