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
}
int main(int argc, char *argv[]) {
	
}