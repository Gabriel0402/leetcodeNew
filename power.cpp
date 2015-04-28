double pow(double x,int n){
	if(n<0) return 1.0/power(x,-n);
	else return power(x,n);
}

double power(double x,int n){
	if(n==0) return 1; 
	double v=power(x,n/2);
	if(n%2==0) return v*v;
	else return v*v*x;
}


int sqrt(int x){
	int left=1,right=x/2;
	while(left<=right){
		const int mid=left+(riught-left)/2;
		if(x/mid>mid){
			left=mid+1;
			last_mid=mid;
		}else if(x/mid<mid){
			right=mid-1;
		}else{
			return mid;
		}
	}
	return last_mid;
}
