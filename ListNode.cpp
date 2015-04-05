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

ListNode *rotateRight(ListNode* head, int k){
	if(head==NULL || k==0） return head;
	int len=1;
	 ListNode *p=head;
	while(p->next){
		len++;
		p=p->next;
	}
	k=len-%len;
	p->next=head;
	for(int i=0;i<k;i++){
		p=p->next;
	}
	head=p->next;
	p->next=NULL;
	return head;
}

ListNode *removeNthFromEnd(ListNode *head, int n){
	ListNode dummy{-1,head};
	ListNode *p=&dummy;
	ListNode *q=&dummy;
	for(int i=0;i<n;i++){
		q=q->next;
	}
	while(q->next){
		p=p->next;
		q=q->next;
	}
	ListNode *tmp = p->next;
	p->next=p->next-next;
	delete tmp; 
	return dummy.next;
}

ListNode *swapPairs(ListNode *head){
	if(head == NULL || head->next ==NULL) return head;
	ListNode dummy(-1);
	dummy.next=head;
	ListNode *prev = &dummy;
	ListNode *cur = prev->next;
	ListNode *next = cur->next;
	while(next && cur->next){
		cur->next=next->next;
		next->next=prev->next; 
		prev->next=next;
		next=cur->next;
		pre=cur;
		cur=pre->next；
		if(cur==NULL) break;
		next=cur->next
		
	}
	return dummy.next;
}

ListNode *reverseKGroup(ListNode *head, int k){
	if(head ==NULL || head->next ==NULL || k<2) return head;
	ListNode dummy(-1);
	dummy.next = head;
	for(ListNode *prev = &dummy, *end = head;end; end=prev->next){
		for(int i=1;i<k && end;i++){
			end =end->next;
		}
		if(end==NULL) break;
		prev=reverse(prev,prev->next,end);
	}
	return dummy.next;
	
}
ListNode *reverse(ListNode *prev, ListNode *begin, ListNode *end){
	ListNode *end_next = end->next;
	for(ListNode *p=begin,*cur=p->next,*next=cur->next;cur!=end_next; p=cur,cur=next, next=next?next->next:NULL){
		cur->next = p;
	}
	begin->next = end_next;
	prev->next = end;
	return begin;
}

struct RandomListNode{
	int val;
	RandomListNode *next, *random;
	RandomListNode(int x): label(x), next(NULL) ,random(NULL){}
};

RandomList *copyRandomList(RandomListNode *head){
	if(head ==NULL) return head;
	RandomListNode *cur = head;
	RandomListNode *copyhead = NULL;
	RandomListNode *copycur = NULL;
	while (cur!=NULL) {
		copycur = new RandomListNode(cur->label)；
		if(copyhead==NULL) copyhead = copycur;
		copycur ->next = cur->next;
		cur->next = copycur;
		cur=cur->next;
	}
	cur = head; 
	while(cur!=NULL){
		cur->next->random = cur->random!=NULL?cur->random->next:NULL;
		cur= cur->next->next;
	}
	cur = head;
	while (cur!=NULL) {
		copycur = cur->next;
		cur->next = cur->next->next;
		copycur->next=cur->next!=NULL?cur->next->next:NULL;
		cur=cur->next;
	}
	return copyhead;
}


ListNode hasCycle(ListNode *head){
	ListNode *slow = head;
	ListNode *fast = head;
	while(fast && fast->next){
		slow=slow->next;
		fast = fast->next->next;
		if(slow == fast) return true;
	}
	return false;
}

ListNode *detectCycle(ListNode *head){
	ListNode* slow = head;
	ListNode* fast = head;
	while(fast && fast ->next){
		slow = slow->next;
		fast = fast->next->next;
		if(slow==fast){
			ListNode *slow2 = head;
			while(slow2!=slow){
				slow=slow->next;
				slow2 = slow2->next;
				
			}
			return slow2;
		}
	}
	return NULL;
}

void reorderList(ListNode *head){
	if(head==NULL || head->next== NULL) return;
	ListNode *slow = head, *fast = head, *prev = NULL;
	while(fast && fast->next){
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
	} 
	prev->next = NULL;
	slow = reverse(slow);
	
	ListNode *curr = head;
	while(curr ->next){
		ListNode *tmp = curr ->next;
		curr->next = slow;
		slow = slow ->next;
		curr->next->next = tmp;
		curr = tmp;
	}
	curr->next=slow;
} 

ListNode *reverse(ListNode *head){
	if(head ==NULL || head->next ==NULL) return head;
	
	ListNode *prev = head;
	for(ListNode *curr = head ->next, *next=curr->next;curr;prev = curr,curr=next,next=next?next->next:NULL){
		curr->next=prev;
	}
	head->next=NULL;
	return prev;
}


int main(int argc, char *argv[]) {
	
}