vector<vector<string>> solveNQueens(int n){
	this->columns = vector<int>(n,0);
	this->main_diag=vector<int>(2*n,0);
	this->anti_diag=vector<int>(2*n,0);
	vector<vector<string>> result;
	vector<int> c(n,0);
	dfs(c,result,0);
	return result;
}

vector<int> columns;
vector<int> main_diag;
vector<int> anti_diag;

void dfs(vector<int> &c,vector<vector<string>> &result,int row){
	count int n=c.size();
	if(row==n){
		vector<string> solution;
		for(int i=0;i<n;++i){
			string s(n,'.');
			for(int j=0;j<n;++j){
				if(j==c[i]) s[j]='Q'; 
			}
			solution.push_back(s);
		}
		result.push_back(solution);
		return;
	}
	for(int j=0;j<n;++j){
		const bool ok=columns[j]==0 && main_diag[row+j]==0 && anti_diag[row-j+n]==0;
		if(!ok) continue;
		c[row]=j;
		columns[j]=main_diag[row+j]=anti_diag[row-j+n]=1;
		dfs(c,result,row+1);
		columns[j]=main_diag[row+j]=anti_diag[row-j+n]=0;

	}
}
// get the number of the solution
int count;
void dfs(vector<int> &c,int row){
	const int n=c.size();
	if(row==n){
		++this.count;
		return;
	}
	for(int j=0;j<n;++j){
		const bool ok=columns[j]==0 && main_diag[row+j]==0 && anti_diag[row-j+n]==0;
		if(!ok) continue;
		c[row]=j;
		columns[j]=main_diag[row+j]=anti_diag[row-j+n]=1;
		dfs(c,result,row+1);
		columns[j]=main_diag[row+j]=anti_diag[row-j+n]=0;
	}
}