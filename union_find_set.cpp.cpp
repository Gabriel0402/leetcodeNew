#include <iostream>


typedef struct ufs_t{
	int *p;
	int size;
}ufs_t;

ufs_t* ufs_create(int n){
	ufs_t *ufs=(ufs_t*)malloc(sizeof(ufs_t));
	int i;
	ufs->p = (int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
		ufs->p[i]=-1;
	}
	return ufs;
}

void ufs_destroy(ufs_t *ufs){
	free(ufs->p);
	free(ufs);
}

int ufs_find(ufs_t *ufs,int x){
	int oldx = x;
	while(ufs->p[x]>=0){
		x=ufs->p[x];
	}
	while (oldx!=x) {
		int temp=ufs->p[oldx];
		ufs->p[oldx]=x;
		oldx=temp;
	}
	return x;
}

int ufs_union(ufs_t *ufs, int x, int y)
{
	const int rx=ufs_find(ufs,x);
	const int ry=ufs_find(ufs,y);
	if(rx==ry) return -1;
	
	ufs->p[rx]+=ufs->p[ry];
	ufs->p[ry]=rx;
	return 0;
}

int ufs_set_size(ufs_t *ufs,int x)
{
	const int rx=ufs_find(ufs,x);
	return -ufs->p[rx];
}

using namespace std;
int main(int argc, char *argv[]) {
	int n,m,k;
	while(cin>>n>>m && n>0){
		ufs_t *ufs=ufs_create(3000);
		while(m--){
			int x,y;
			int rx,ry;
			cin>>k;
			k--;
			cin>>x;
			rx=ufs_find(ufs,x);
			while(k--){
				cin>>y;
				ry=ufs_find(ufs,y);
				ufs_union(ufs,rx,ry);
			}
		}
		cout<<ufs_set_size(ufs,0)<<endl;
		ufs_destroy(ufs);
	}
}