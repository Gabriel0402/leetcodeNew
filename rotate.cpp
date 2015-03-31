#include <iostream>

using namespace std;

class Solution{
public: 
	void rotate(vector<vector<int>>& matrix)
	{
		const int n=matrix.size();
		for(int i=0;i<n;++i){
			 for(j=0;j<n-i;++j){
				swap(matrix[i][j],matrix[n-1-i][n-1-j]);
			} 
		}
		
		for(int i=0;i<n/2;++i){
			for(int i=0;i<n;++j){
				swap(matrix[i][j],matrix[n-1-i][j]);
			}
		}
	}
} 


int main(int argc, char *argv[]) {
	
}