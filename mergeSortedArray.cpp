void merge(int a[],int m, int B[], int n){
	int ia=m-1,ib=n-1,icur=m+n-1;
	while(ia>=0 &&ib>=0){
		a[icur--]==a[ia]>b[ib]?a[ia--]:b[ib--];
	}
	while(ib>=0){
		a[icur--]=b[ib--];
	}
}

//merge two sorted list
ListNode *mergeTwoLists(ListNode *l1,ListNode *l2){
	if(l1==NULL) return l2;
	if(l2==NULL) return l1;
	ListNode head(-1);
	ListNode *p=&head;
	for(;l1!=NULL && l2!+NULL;p=p->next){
		if(l1->val>l2->val){
			p->next=l2;
			l2=l2->next;
		}
		else{
			p->next=l1;
			l1=l1->next;
		}
		p->next=l1!=NULL?l1:l2;
		return head.next;
	}
}

//merge K Lists
ListNode *mergeKLists(vector<ListNode *> &lists){
	if(lists.size()==0) return NULL;
	ListNode *p=lists[0];
	for(i=1;i<lists.size();i++){
		p=mergeTwoLists(p,lists[i]);
	}
	return p;
}

ListNode *insertionSortList(ListNode *head){
	ListNode dummy(INT_MIN);
	for(ListNode *cur=head;cur!=NULL){;		
		auto pos=findInsertPos(&dummy,cur->val);
		ListNode *tmp=cur->next;
		cur->next=pos->next;
		pos->next=cur;
		cur=tmp;
	} 
	return dummy.next;
}

ListNode *findINsertPos(ListNode *head,int x){
	ListNode *pre=NULL;
	for(ListNode *cur=headlcur!=NULL && vur->val<=x;pre=cur,cur=cur->next)
		;
    return pre;
}

ListNode *sortList（ListNode *head）{
	if(head==NULL||head->next==NULL) return head;
	ListNode *fast=head, *slow=head;
	while(fast->next!=NULL && fast->next->next!=NULL){
		fast=fast->next->next;
		slow=slow->next;
	}
	fast=slow;
	slow=slow->next;
	fast->next=NULL;
	ListNode *l1=sortList(head);
	ListNode *l2=sortList(slow);
	return mergeTwoLists(l1,l2);
}

