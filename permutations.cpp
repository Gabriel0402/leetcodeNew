//permutations time:o(n!) space: o(n)

vector<vector<int>> permute(vector<int>& num){
	sort(num.begin(),num.end());
	vector<vector<int>> result;
	vecotr<int> path; 
	dfs(num,path,result);
	return result; 
}

void dfs(const vector<int>& num, vector<int> &path, vector<vector<int>> &result)
{
	if(path.size()==num.size()){
		result.push_back(path);
		return;
	}
	for(auto i:num){
		auto pos=find(path.begin(),path.end(),i);
		if(pos==path.end()){
			path.push_back(i);
			dfs(num,path,result);
			path.pop_back();
		}

	}
}

vector<vector<int>> permute(vector<int> &num){	
	vector<vector<int>> result;
	bfs(result,num,0);
	return result;
}

void bfs(vector<vector<int>> &result,vector<int> &num,int n){
	if(n==num.size()){
		result.push_back(num);
		return;
	}
	else{
		for(int i=n;i<num.size();i++){
			swap(num[i],num[n]);
			bfs(result,num,n+1);
			swap(num[i],num[n]);
		}
	}
}

//permutation II
vector<vecsotr<int>> permuteUnique(vector<>int) &num{
	sort(num.begin(),num.end());
	unordered_map<int,int> count_map;
	for_each(num.begin,num.end(),[&count_map](int e){
		if(count_map.find(e)!=count_map.end()) count_map[e]++;
		else count_map[e]=1;
	})
	vecotr<pair<int,int>> elems;
	for_each(count_map.begin(),count_map.end(),[&elems](const pair<int,int> &e){
		elems.push_back(e);
	});
	vector<vector<int>> result;
	vector<int> p;
	n=num.size();
	permute(elems.begin(),elems.end(),p,result);
	return result; 
}

size_t n;

typedef vector<pair<int,int>>:: const_iterator Iter;
void permute(Iter first, Iter last, vector<int> &p,vector<vector<int>> &result){
	if(n==p.size()){
	   result.push_back(p);
	}
	for(auto i=first;i!=last;i++){
		int count=0;
		for(auto j=p.begin();j!=p.end();j++){
			if(i->first==*j){
				count++;
			}
		}
		if(count<i->second){
			p.push_back(i->first);
			permute(first,last,p,result);
			p.pop_back();
		}
	}
}

vector<vector<int>> combine(int n,int k){
	vector<vector<int>> result;
	vector<int> path;
	dfs(n,k,1,0,path,result);
	return result;
}

static void dfs(int n,int k, int start,int cur, vector<int> &path, vector<vector<int>> &result){
	if(cur==k){
		result.push_back(path);
	}
	for(int i=start;iu<=n;++i){
		path.push_back(i);
		dfs(n,k,i+1,cur+1,path,result);
		path.pop_back(); 
	}
}