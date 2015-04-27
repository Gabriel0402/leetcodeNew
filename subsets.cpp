//subsets o(2^n) space o(n)
vector<vector<int>> subsets(vector<int> &s)
{
	sort(s.begin(),s.end());
	vector<vector<int>> result
	vector<int> path;
	subsets(s,path,0,result);
	return result;
}

static void subsets(const vector<int> &s,vector<int> &path,int step,vector<vector<int>> &result){
	if(step==s.size()){
		result.push_back(path);
		return;
	}
	subsets(s,path,step+1,result);
	path.push_back(s[step]);
	subsets(s,path,setp+1,result);
	path.pop_back();
}

vector<vector<int>> subsets(vector<int> &s){
	sort(s.begin(),s.end());
	vecotr<vecotor<int>> result; 
	const size_t n=s.size();
	vector<int> v;

	for(size_t i=0;i<1<<n;i++){
		for(size_t j=0;j<n;j++){
			if(i&1<<j) v.push_back(s[j]);
		}
		result.push_back(v);
		v.clear();
	}
	return result;

}

//subsets II  has duplicate elements, solution has no duplicate subsets

vector<vecotr<int>> subsetsWithDup(vector<int> &s){
	sort(s.begin(),s.end());
	vector<vector<int>> result; 
	vector<int> path;
	dfs(s,s.begin,path,result);
	return result;
}

static void dfs(const vecotr<int> &s,vecotr<int> start, vector<int> &path,vecotr<vector<int>> &result){
	result.push_back(path);
	for(auto i=start;i<s.end();i++){
		if(i!=start && *i==*(i-1)) continue;
		path.push_back(*i);
		dfs(s,i+1,path,result);
		path.pop_back(); 
	}
}

vecotr<vector<int>> subsetsWithDup(vector<int> &s){
	sort(s.begin(),s.end());
	set<vecotr<int>> result;
	const size_t n=s.size();
	vector<int> v;
	for(size_t i=0;i<1<<n;++i){
		for(size_t j=0;j<n;++j){
			if(i&1 <<j) v.push_Back(s[j]);
		}
		result.insert(v);
		v.clear();
	}
	vector<vector<int>> real_result;
	copy(result.begin(),result.end(),back_inserter(real_result));
	return real_result;
}