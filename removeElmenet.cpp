#include <iostream>

using namespace std;

class Solution{
public: 
	int removeElement(int a[],int n, int elem){
		int index = 0;
		for(int i=0;i<n;i++){
			if(a[i]!=elem){
				a[index++]=a[i];
			}
		}
		return index; 
	}
}
int main(int argc, char *argv[]) {
	
}