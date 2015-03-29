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
	
	int threeSumClosest(vector<int>& num, int target){
		int result=0;
		int min_gap = INT_MAX;
		sort(num.begin(),num.end());
		for(auto a=num.begin();a!=prev(num.end(),2);a++){
			auto b=next(a);
			auto c=prev(num.end());
			while(b<c){
				const int sum=*a+*b+*c;
				const int gap=abs(sum-target);
				if(gap<min_gap){
					result=sum;
					min_gap=gap;
				}
				if(sum<target) ++b;
				else --c;
			}
		}
		return result;
	}
	
	vector<vector<int>> fourSum(vector<int> &num, int target){
		vector<vector<int>> result;
		if(num.size()<4) return result;
		sort(num.begin(),num.end());
		unordered_map<int, vector<pair<int,int> > > cache;
		for(size_t a=0; a<num.size();a++){
			for(size_t b=a+1;b<num.size();b++){
				cache[num[a]+num[b]].push_back(pair<int,int>(a,b)); 
			}
		}
		for(int c =0;c<num.size();++c){
			for(size_t d=c+1;d<num.size();++d){
				const int key = target-num[c]-num[d];
				if(cache.find(key)==cache.end()) continue;
				
				const auto& vec = cache[key];
				for(size_t k=0;k<vec.size();++k){
					if(c<=vec[k].second) continue;
					result.push_back({num[vec[k].first],num[vec[k].second],num[c],num[d]});
				}
			}
		}
		sort(result.begin(),result.end());
		result.erase(unique(result.begin(),result.end()));
		return result;
	}
	
}
		
int main(int argc, char *argv[]) {
	
}