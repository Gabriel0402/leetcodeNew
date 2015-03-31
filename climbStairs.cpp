#include <iostream>

using namespace std;


class Solution{
public: 
	int climbStairs(int n){
		int prev=0;
		int cur = 1; 
		for(int i=1;i<=n;++i){
			int tmp=cur;
			cur+=prev;
			prev=tmp;
		}
		return cur;
	} 
	
	int climbStairs(int n){
		int a[3];
		a[0]=0; 
		a[1]=1;
		for(int i=2;i<n;i++){
			a[2]=a[0]+a[1];
			a[0]=a[1];
			a[2]=a[1];
		}
		return a[2];
	}
}
int main(int argc, char *argv[]) {
	
}