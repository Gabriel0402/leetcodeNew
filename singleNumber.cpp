#include <iostream>

using namespace std;  

class Solution{
public:
	int singleNumber(int a[], int n){
		int x=0;
		for(size_t i=0; i<n; ++i){
			x^=a[i];
		}
		return x;
	}
	
	int singleNumber(int a[], int n){
		int one=0,two = 0, three = 0;
		for(int i=0;i<n;i++){
			two |=(one & a[i]);
			one^ = a[i];
			three =~（one & two);
			one &=three;
			two &=three;
		}
		return one;
	}
}
int main(int argc, char *argv[]) {
	
}