vector<vector<int>> f;

int uniquePaths(int m,int n){
	f=vector<vector<int>>(m+1,vector<int>(n+1,0));
	return dfs(m,n);
} 

int dfs(int x,int y){
	if(x<1 || y<1) return 0;
	if(x==1 && y==1) return 1;
	return getOrUpdate(x-1,y)+getOrUpdate(x,y-1);
}

int getOrUpdate(int x,int y){
	if(f[x][y]>0) return f[x][y];
	else return f[x][y]=dfs(x,y);
}

//dp solution
int uniquePaths(int m,int n){
	vector<int> f(n,0);
	f[0]=1;
	for(int i=0;i<m;i++){
		for(int j=1;j<n;j++){
			f[j]=f[j-1]+f[j];
		}
	}
	return f[n-1];
}

//dp solution with obstacles
int uniquePathsWithOstacles(vector<vector<int>> &obstacleGrid){
	const int m=obstacleGrid.size();
	const int n=obstacleGrid[0].size();

	if(obstacleGrid[0][0]||obstacleGrid[m-1][n-1]) return 0;
	vector<int>f(n,0);
	f[0]=obstacleGrid[0][0]?0:1;
	for(int i=0;i<m;i++){
		for(int j=1;j<n;j++){
			f[j]=obstacleGrid[i][j]?0:(j==0?0:f[j-1])+f[j];
		}
	}
	return f[n-1];
}