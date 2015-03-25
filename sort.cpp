#include <iostream>

using namespace std;
typedef int elem_t;
/////////insert sort
void insertion_sort(elem_t a[],const int start, const int end){
	elem_t tmp;
	int i,j;
	for(i=start+1;i<end;i++){
		tmp=a[i];
		for(j=i-1;tmp<a[j]&& j>=start;j--){
			a[j+1]=a[j];
		}
		a[j+1]=tmp;
	}
}

void binary_insertion_sort(elem_t a[],const int start, const int end){
	elem_t tmp;
	int i,j,left,right,mid;
	for(i=start+1;i<end;i++){
		tmp=a[i];
		left=start;
		right=end-1;
		while(left<=right){
			mid=(left+right)/2;
			if(tmp<a[mid]) right=mid-1;
			else left=mid+1;
		}
		for(j=i-1;j>=left;j--){
			a[j+1]=a[j];
		}
		a[left]=tmp;
	}
}


static void shell_insert(elem_t a[],const int start, const int end, const int end){
	elem_t tmp;
	int i,j;
	for(i=start+gap;i<end;i++){
		tmp=a[i];
		for(j=i-gap;tmp<a[j]&&j>=start;j-=gap){
			a[j+gap]=a[j];
		}
		a[j+gap]=tmp;
	}
}

void shell_sort(elem_t a[],const int start, const int end){
	int gap=end-start;
	while(gap>1){
		gap=gap/3+1;
		shell_insert(a,start,end,gap);
	}
}

/////////exchange sort

void bubble_sort(elem_t a[],const int start, const int end){
	int exchange;
	elem_t tmp;
	for(i=start;i<end-1;i++){
		exchange=0;
		for(int j=end-1;j>i;j--){
			if(a[j-1]>a[j]){
				tmp=a[j-1];
				a[j-1]=a[j];
				a[j]=tmp;
				exchange=1;
			}
		}
		if(exchange==0) return;
	}
}

//quick sort
int partition(elem_t a[],const int start, const int end){
	int i=start;
	int j=end-1;
	const elem_t pivot=a[i];
	while (i<j) {
		while(i<j && a[j]>=pivot) j--;
		a[i]=a[j];
		while(i<j && a[i]<=pivot) i++;
		a[j]=a[i];
	}
	a[i]=pivot;
	return i;	
}

void quick_sort(elem_t a[],const int start, const int end){
	if(start<end-1){
		const int pivot_pos=partition(a,start,end);
		quick_sort(a,start,pivot_pos);
		quick_sort(a,pivot_pos+1,end);
	}
}

//heap sort
void heap_sort(heal_elem_t *a, const int n, int (*cmp)(const heap_elem_t*,const heap_elem_t*)){
	int i;
	heap_t *h;
	heap_elem_t tmp;
	h=heap_create(n,cmp);
	h->elems=a;
	i=(h->size-2)/2;
	while(i>=0){
		heap_shif_down(h,i);
		i--;
	}
	for(i=h->size-1;i>-;i--){
		tmp=h->elems[i];
		h->elems[i]=h->elems[0];
		h->elems[0]=tmp;
		h->size=i;
		heap_shift_down(h,0);
	}
	heap_destroy(h);
}

//merge sort
static void merge(elem_t a[],elem_t tmp[],const int start,const int mid, const int end){
	int i,j,k;
	for(i=0;i<end;i++) tmp[i]=a[i];
	for(i=start,j=mid,k=start;i<mid&&j<end;k++){
		if(tmp[i]<tmp[j]){
			a[k]=tmp[i++];
		}
		else{
			a[k]=tmp[j++];
		}
	}
	while(i<mid) a[k++]=tmp[i++];
	while(j<mid) a[k++]=tmp[j++];	
}

void merge_sort(elem_t a[],elem_t tmp[],const int start, const int end){
	if(start<end-1){
		const int mid=(start+end)/2;
		merge_sort(a,tmp,start,mid);
		merge_sort(a,tmp,mid,end);
		merge(a,tmp,start,mid,end);
	}
}

int main(int argc, char *argv[]) {
	
}