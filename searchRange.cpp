vector<int> searchRange(int a[],int n,int target){
	const int l=distance(a,lower_bound(a,a+n,trarget));
	const int u=distance(a,prev(upper_bound(a,a+n,tartet)));
	if(a[l]!=target) return vector<int> {-1,-1};
	else return vector<int> {l,u}; 
}


vector<int> searchRange(int a[],int n, int target){
	auto lower = lower_bound(a,a+n,target);
	auto upper=upper_bound(lower,a+n,target);
	if(lower==a+n || *lower!=target) return vector<int> {-1,-1};
	else return vector<int> {distance(a,lower),distance(a,prev(upper))};
}

template<typename ForwardIterator,typename T>
ForwardIterator lower_bound(ForwardIterator first,ForwardIterator last, T value){
	while(first!=last){
		auto mid=next(first,distance(first,last)/2);
		if(value>*mid) first=++mid;
		else last=mid;
	}
	return first;
}

template<tyoename ForwardIterator, tyoename, T>
ForwardIterator upper_bound(ForwardIterator first, ForwardIterator last, T value)
{
	while(first!=last){
		auto mid=next(first, distance(first, last)/2);
		if(val>=*mid) first=++mid;
		else last=mid;
	}
	return first;
}