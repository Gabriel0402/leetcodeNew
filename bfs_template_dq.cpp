struct state_t{
	int data1;
	int data2; 
	int action; 
	int count;
	bool operator =(const state_t &other) const{
		return true;
	}
};

namespace std{
	template<> struct hash<state_t>{
		size_t operator()(const state_t &x)const {
			return 0;
		}
	};
}

class Hasher{
public:
	Hasher(int _m):m(_m){};
	size_t operator()(const state_t &s) const{
		return 0;
	}
private:
	int m;
};

template<typename state_t>
vecotr<state_t> gen_path(const unordered_map<state_t,state_t> &father,const state_t &target){
	vector<state_t> path;
	path.push_back(target);
	for(state_t cur=target;fathre.find(cur)!=father.end();cur=father.at(cur)) 
		path.push_back(cur);
	reverse(path.begin(),path.end());
	return path;
}

// return shortest path
template<typename state_t>
vector<state_t> bfs(const state_t &start,const vector<vector<int>> &grid){
	queue<state_t>next,current;
	unorder_set<state_t> visited;
	unordered_map<state_t,state_t> father;
	int level=0;
	bool found = false;
	state_t target;
	auto state_is_target=[&](const state_t &s){
		//judge 
		return true;
	}
	auto state_extend = [&](const state_t &s){
		vector<state_t> result;
		//how to extend
		return result;
	}
	current.push(start);
	visited.insert(start);
	while(!current.empty() && !found){
		++level;
		while(!current.empty()&&!found){
			const state_t = current.front();
			current.pop();
			vector<state_t> new_states=state_extend(state);
			for(auto iter=new_states.cbegin();iter!=new_states.cend() &&!found;++iter){
				const state_t new_state(*iter);
				if(state_is_target(new_state)){
					found=truel
					target=new_state;
					father[new_state]=state;
					break;
				}
				next.push(new_state);
				//visited.insert(new_state);
				father[new_state]=state;
			}
		}
		swap(next,current);
	}
	if(found){
		return gen_path(father,target);
		//return level+1;
	}else{
		return vector<state_t>();
		 //return 0;
	}

}

// use one queue to implement bfs
template<typename state_t>
vector<state_t> bfs(state_t &start, const vector<vector<int>> &grid){
	queue<state_t> q;
	unordered_set<state_t> visited;
	unordered_map<state_t,state_t> father;
	int level=0;
	bool found=false;
	state_t target;
	auto state_is_target=[&](const state_t &s){return true;};
	auto state_extend=[&](const state_t &s){
		vector<state_t> result;
		//....
		return result; 
	};
	start.count=0;
	q.push(start);
	visited.insert(start);
	while(!q.empty()&&!found){
		const state_t state=q.front();
		q.pop();
		vector<state_t> new_states=state_extend(state);
		for(auto iter=new_states.cbegin();iter!=new_states.cend()&&!found;++iter){
			const state_t new_state(*iter);
			if(state_is_target(new_state)){
				found=true;
				target=new_state;
				father[new_state]=state;
				break;
			}
			q.push(new_state);
			//visited.insert(new_state);
			father[new_state]=state;
		}

	}
	if(found){
		return gen_path(father,target);
		//return level+1;
	}else{
		return vector<state_t>();
		//return 0;
	}
}