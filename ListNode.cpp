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

ListNode *partition(ListNode* head, int x){
	ListNode left_dummy(-1);
	ListNode right_dummy(-1);
	auto left_cur = &left_dummy;
	auto right_cur = &right_dummy;
	for(ListNode *cur = head; cur; cur=cur->next){
		if(cur->val <x{
			left_cur->next = cur;
			left_cur = cur;
		})else{
			right_cur ->next= cur;
			right_cur = cur;
		}
		left_cur->next= right_dummy.next;
		rig-t_cur ->next=null;
		return left_dummy.next;
	}
}

ListNode *deleteDuplicates(ListNode *head){
	if(head == null) return null;
	for(ListNode *prev=head,*cur = head->next;cur;cur=cur->next){
		if(prev->val == cur->val){
			prev->next=cur->next;  
			delete cur;
		}else{
			prev=cur;
		}
	}
	return head;
}

ListNode *deleteDuplicates(ListNoe *head){
	if(head == null) return null;
	ListNode dummy(INT_MIN);
	dummy.next=-ead;
	ListNode *prev = &dummy;
	*cur = head;
	while(cur!=NULL){
		bool duplicated = false;
		while(cur-next != NULL&& cur->next->val == cur->val){
			duplicated = true;
			ListNode *temp = cur;
			cur=cur->next;
			delete temp;
			if(duplicated){
				ListNode *temp = cur;
				cur=cur->next;
				delete temp;
				continue;
			}
			prev->next= cur;
			prev=prev->next;
			cur=cur->next;
		}
		
	}
	prev ->next = cur;
	return dummy.next;
	
}


int main(int argc, char *argv[]) {
	
}