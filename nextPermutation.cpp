#include <iostream>

using namespace std;

class Solution{
	void nextPermutation(vector<int> &num)
	{
		next_permutation(num.begin(),num.end());
	}
	
	string getPermutation(int n, int k){
		string s(n,'0');
		for(int i=0;i<n;i++){
			s[i]+=i+1;
		}
		for(int i=0;i<k-1;i++){
			next_permutation(s.begin(),s.end());
		}
		return s;
	}
	template<typename BidIt>
	bool next_premutation(BidIt first,BidIt last){
		const auto rfirst = reverse_iterator<BidIt>(last);
		const auto rlast = reverse_iterator<BidIt>(first);
		auto pivot = next(rfirst);
		
		while (pivot !=rlast && *pivot>*prev(pivot)) {
			++ pivot;
		}
		if(pivot ==rlast){
			reverse(rfirst,rlast);
			return false;
		} 
		
		auto change = find_if(rfirst,pivot,bind1st(less<int>(),*pivot));
		swap(*change, *pivot); 
		reverse(rfirst,pivot);
		return true;
	}
	 
}

int main(int argc, char *argv[]) {
	
}