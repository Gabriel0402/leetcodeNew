#include <iostream>

using namespace std;
class Solution{
public:
	double findMedianSortedArrays(int a[],int m, int b[], int n){
		int total = m+n;
		if(total & 0x1){
			return find_kth(a,m,b,n,total/2+1);
		}
		else{
			return (find_kth(a,m,b,n,total/2)+find_kth(a,m,b,n,total/2+1))/2.0;
		}
	}
	
private:
	double find_kth(int a[], int m, int b[], int n, int k){
		if(m>n) return find_kth(b,n,a,m,k);
		if(m==0) return b[k-1];
		if(k==1) return min(a[0],b[0]);
		
		int ia=min(k/2,m),ib=k-ia;
		if(a[ia-1]<b[ib-1]) return find_kth(a+ia,m-ia,b,n,k-ia);
		else if(a[ia-1]>b[ib-1]) return find_kth(a,m,b-ib,n-ib,k-ib);
		else return a[ia-1];
	}
}


int main(int argc, char *argv[]) {
	
}