#include <iostream>

using namespace std;

class Solution{
public:
	int search(int a[], int n, int target){
		int first = 0, last = n;
		while(first!=last){
			const int mid=(first+last)/2;
			if(a[mid] == target){
				return mid;
			}
			if(a[first]<=a[mid]){
				if(a[first]<=target && target<a[mid]){
					last=mid;
				}
				else{
					first=mid+1;
				}
			}
			else{
				if(a[mid]< target && target<=a[last-1]){
					first=mid+1;
				}
				else{
					last=mid;
				}
			}
		}
		return -1;
	}
}

class Solution{
public: 
	bool search(int a[],int n, int target){
		int first = 0, end = n;
		while(first!=end){
			const int mid = (first + end)/2;
			if(a[mid]==target) return true;
			if(a[first]<a[mid]){
				if(a[first]<=target && target<a[mid]){
					last = mid;
				}
				else{
					first = mid+1;
				}
			}else if(a[first]>a[mid]){
				if(a[mid]<target && target<=a[last-1]){
					first = mid+1;
				}
				else{
					last=mid;
				}
				
			}
			else{
				first ++;
			}
		}
		return false;
		
	}
}
int main(int argc, char *argv[]) {
	
}