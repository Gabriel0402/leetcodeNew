#include <iostream>

using namespace std;

class Solution{
public:
	vector<int> grayCode(int n){
		vector<int> result;
		const size_t size=1<<n;
		result.reverse(size);
		for(size_t i=0;i<size;i++){
			result.push_back(binary_to_gray(i));
		}
		return result;
		
	}
	
	vector<int> grayCode(int n){
		vector<int> result; 
		result.reverse(1<<n);
		result.push_back(0);
		for(int i=0;i<n;i++){
			const int highest_bit = 1<<i;
			for(int j=result.size()-1;j>=0;j--){
				result.push_back(highest_bit|result[j]);
			}
			return result;
		} 
	}
private:
	static unsigned int binary_to_gray(unsigned int n){
		return n^(n>>1);
	}
}
int main(int argc, char *argv[]) {
	
}