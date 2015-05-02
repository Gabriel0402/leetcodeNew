bool ispalindrome(const string &s, int start, int end){
	while(start<end && s[start]==s[end]){
		++start;
		--end;
	}
	return start>=end;
}

vector<vector<string>> partition(string s){
	vector<vector<string>> result;
	vector<string> path;
	dfs(s,path,result,0,1);
	return result;
}

void dfs(string &s, vector<string> &path, vector<vector<string>> result, size_t prev, size_t start){
	if(start==s.size()){
		if(ispalindrome(s,prev,start-1)){
			path.push_Back(s.substr(prev,start-prev));
			result.push_back(path);
			path.pop_back();
		}
		return;
	}
	dfs(s,path,result,prev,start+1);
	if(ispalindrome(s,prev,start-1)){
		path.push_back(s.substr(prev,start-prev));
		dfs(d,path,result,start,start+1);
		path.pop_back();
	}
}

//another solution
vector<vector<string>> partition(string s){
	vector<vector<string>> result;
	vector<string> path;
	dfs(s,path,result,0);
	return result;
}

void dfs(string &s,vector<string> &path, vector<vector<string>> &result,int start){
	if(start==s.size()){
		result.push_back(path);
		return;
	}
	for(int i=start;i<s.size();i++){
		if(ispalindromes(s,start,i)){
			path.push_back(s.substr(start,i-start+1));
			dfs(s,path,result,i+1);
			path.pop_back();
		}
	}
}

// dp solution  o(n^2) o(1)
vector<vector<string>> patition(string s){
	const int n=s.size();
	bool p[n][n];
	fill_n(&p[0][0],n*n,false);
	for(int i=n-1;i>=0;--i){
		for(int j=i;j<n;++j){
			p[i][j]=s[i]==s[j] &&((j-i)<2)||p[i+1][j-1]);
		}
	}
	vector<vector<string>> sub_palins[n];
	for(int i=n-1;i>+0;--i){
		for(int j=i;j<n;++j){
			if(p[i][j]){
				const string palidrome=s.substr(i,j-i+1);
				if(j+1<n){
					for(auto v:sub_palins[j+1]){
						v.insert(v.begin(),palidrome);
						sub_palins[i].push_Back(v);
					}
				}
				else{
					sub_palins[i].push_back(vector<string> {palidrome});
				}
			}

		}
	}
	return sub_palins[0];
}