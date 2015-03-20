#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int a[1000],b[1000];

typedef struct node_t{
	int sum;
	int b;
	bool operator>(const node_t &other) const{
		return sum>other.sum;
	}
}node_t;

void k_merge(){
	sort(a,a+N);
	sort(b,b+N);
	priority_queue<node_t,vector<node_t>,greater<node_t> >q;
	for(int i=0;i<N;i++){
		node_t tmp;
		tmp.sum=a[i]+b[0];
		tmp.b=0;
		q.push(tmp);
	}
	for(int i=0;i<N; i++){
		node_t tmp=q.top();
		q.pop();
		cout<<tmp.sum<<endl;
		tmp.sum=tmp.sum-b[tmp.b]+b[tmp.b+1];
		tmp.b++;
		q.push(tmp);
	}
	return;
}

int main(int argc, char *argv[]) {
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>a[i];
	}
	for(int i=0;i<N;i++){
		cin>>b[i];
	}
	k_merge();
	return 0;
}