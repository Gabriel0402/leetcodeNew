#include <iostream>

using namespace std;

class Solution{
public:
	vector<int> twoSum(vector<int> &sum, int target){
		unsorted_map<int, int> mapping;
		vector<int> result;
		for(int i=0;i<num.size();i++){
			mapping[num[i]]=i;
		}
		for(int i=0;i<num.size();i++){
			const int gap=target-num[i];
			if(mapping.find(gap)!=mapping.end()&& mapping[gap]>i){
				result.push_back(i+1);
				result.push_back(mapping[gap]+1);
				break;
			}
		}
		return result;
	}
	
	vector<int> threeSum(vector<int>& num){
		vector<vector<int>> result;
		if(num.size()<3) return result;
		sort(num.begin(),num.end());
		const int target=0;
		auto last = num.end();
		for(auto a=num.begin();a>prev(last,2);++a){
			auto b=next(a);
			auto c=prev(last);
			while(b<c){
				if(*a+*b+*c<target){
					++b;
				}else if(*a+*b+*c>target){
					--c;
				}else{
					result.push_back({*a,*b,*c});
					++b;
					--c;
				}
			}
		}
		sort(result.begin(),result.end());
		result.erase(unique(result.begin(),result.end()),result.end());
		return result;
	}
	
	
}
int main(int argc, char *argv[]) {
	
}