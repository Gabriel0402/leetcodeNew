#include <iostream>

using namespace std;

int trap(int a[ ],int n)
{
	int *max_left = new int[n]();
	int *max_right= new int[n]();
	
	for(int i=0;i<n;i++){
		max_left[i]=max(max_left[i-1],a[i-1]);
		max_right[n-i-1]=max(max_right[n-i],a[n-i]);
	}
	int sum=0;
	for(int i=0;i<n;i++){
		int height =min(max_left[i],max_right[i]);
		if(height>a[i]){
			sum+=height-a[i];
		}
	}
	delete[] max_left;
	delete[] max_right;
	return sum;
}

int trap(int a[],int n){
	stack<pair<int,int>> s; 
	int water = 0;
	for(int i=0;i<n;i++){
		int height=0;
		while (!s.empty()) {
			int bar = s.top().first; 
			int pos = s.top().second;
			water+=(min(bar,a[i])-height)*(i-pos-1);
		 	height = bar;
		   if(a[i]<bar) break;	
			else s.pop();
			
		}
		s.push(make_pair(a[i],i));
	} 
	return water;
}
int main(int argc, char *argv[]) {
	
}