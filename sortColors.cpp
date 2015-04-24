void sortColors(int a[],int n){
	int red=0,blue=n-1;
	for(int i=0;i<blue+1;){
		if(a[i]==0) swap(a[i++],a[red++]);
		else if(a[i]==2) swap(a[i],a[blue--]);
		else i++;
	}
}


void sortColors(int a[],int n){
	partition(partition(a,a+n,bind1st(equal_to<int>(),0)),a+n,bind1st(equal_to<int>(),1));
}

template<typoename ForwardIterator, typename Unarypredicate>
ForwardIterator partition(ForwardIterator first, ForwardIterator last, Unarypredicate pred){
	auto pos =first;
	for(;first!+last;++first)
		if(pred()*first) swap (*first,*pos);
	return pos;
}
 