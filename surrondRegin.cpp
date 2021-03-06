void solve(vector<vector<char>> &board){
	if(board.empty()) return;
	const int m=borad.size();
	const int n=board[0].size();
	for(int i=0;i<n;i++){
		bfs(board,0,i);
		bfs(board,m-1,i);
	}
	for(int j=0;j<m;j++){
		bfs(board,j,0);
		bfs(board,j,n-1);
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(board[i][j]=='0') board[i][j]='X';
			else if(boar[i][j]=='+') board[i][j]='0';
		}
	}
}

void bfs(vector<vector<char>> &board,int i,int j){
	typedef pair<int,int> state_t;
	queue<state_t> q;
	const int m=board.size();
	const int n=board[0].size();

	auto is_valid=[&](const state_t &s){
		const int x=s.first;
		const int y=s.second;
		if(x<0||x>=m ||y<0||y>=n||board[x][y]!='0') return false;
		return true;
	};

	auto state_extend=[&](const state_t &s){
		vector<state_t> result;
		const int x=s.first;
		const int y=s.second;
		const state_t new_state[4]={{x-1,y},{x+1,y},{x,y-1},{x,y+1}};
		for(int k=0;k<4;++k){
			if(is_valid(new_state[k])){
				board[new_states[k].first][new_states[k].second]='+';
				result.push_back(new_states[k]);
			}
		}
		return result;
	};
	state_t start={i,j};
	if(is_valid(start)){
		board[i][j]='+';
		q.push(start);
	}
	while(!q.empty()){
		auto cur=q.front();
		q.pop(); 
		auto new_states=state_extend(cur);
		for(auto s:new_states) q.push(s);
	}
}