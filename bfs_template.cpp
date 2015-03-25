#include <iostream>

using namespace std;

template<typename state_t>
vecotr<state_t> gen_path(const unordered_map<state_t,state_t> &fater,const state_t &target){
	vector<state_t> path;
	path.push_back(target);
	state_t cur=target;
	while(father.find(cur)!=father.end()){
		cur=father.at(cur);
		path.push_back(cur);
	}
	reverse(path.begin(),path.end());
	return path;	
}

template<typename state_t>
vector<state_t> bfs(state_t &start, bool(*state_is_target)(const state_t &). vector<state_t>(*state_extend)(const state_t&,unordered_set<string> &visited)){
	queue<state_t>next, current;
	unordered_set<state_t> visited;
	unordered_set<state_t,state_t> father;
	
	int level=0;
	bool found = false;
	state_t target;
	
	current.push(start);
	visited.insert(start);
	while(!current.empty() && ！found){
		++level;
		while(!current.empty() && !found){
			const state_t state = current.front();
			current.pop();
			vector<state_t> new_states = state_extend(state,visited);
			for(auto iter = new_states.begin();iter!=new_states.end() && !found;++iter){
				const state_t new_state(*iter);
				if(state_is_target(new_state){
					found=true;
					target=new_state;
					father[new_state]=state;
					break;
				})
				next.push(new_state);
				father[new_state]=state;
			}
		}
		swap(next,current);
	}
	if(found){
		return gen_path(father,target);
	}else{
		return vector<state_t>();
	}
}

int main(int argc, char *argv[]) {
	
}