int maxSubArray(int a[],int n){
	int result = INT_MIN,f=0;
	for(int i=0;i<n;++i){
		f=max(f+a[i],a[i]);
		result=max(f,result);
	}
	return result;
}