int searchInsert(int a[],int n,int target){
	return lower_bound(a,a+n,target)-a;
}

template<typename ForwaredIterator,typename T>
ForwaredIterator lower_bound(ForwaredIterator first, ForwaredIterator last, T value){
	while(first!=last){
		auto mid=next(first,distance(first,last)/2);
		if(value>*mid) first=++mid;
		else last=mid;
	}
	return first;
}