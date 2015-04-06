#include <iostream>

using namespace std;

char *strStr(const char *haystack, const char *needle){
	int m=strlen(haystack);
	int n=strlen(needle);
	if(n>m) return NULL;
	for(int i=0;i<m-n;i++){
		bool flag =true;
		for(int j=0;j<m;j++){
			if(haystack[i+j]!=needle[j]){
				flag=false;
				break;
			}
		} 
		if(flag){
			return haystack+i;
		}
	}
	return NULL;
	
}


//KMP
class Solution{
public:
	char *strStr(const char *haystack, const char *needle){
		int pos = kmp(haystack,needle);
		if(pos==-1) return NULL;
		else return (char*) haystack+pos;
	} 

private:
	static void compute_prefix(const char *pattern, int next[]){
		int i;
		int j=-1;
		const int m=strlen(pattern);
		next[0]=j;
		for(i=1;i<mli++){
			while(j>-1 && pattern[j+1]!=patter[i]) j=next[j];
			if(pattern[i]==pattern[j+1]) j++;
			next[i]=j;
			}	
		}	
}

static int kmp(const char *text, const char *pattern){
	int i;
	int j=-1;
	const int n=strlen(text);
	const int m=strlen(pattern);
	if(n==0 && m==0) return 0;
	if(m==0) return 0;
	int *next = (int*) malloc(sizeof(int)*m);
	
	compute_prefix(pattern,next);
	for(i=0;i<n;i++){
		while(j>-1 && pattern[j+1]!=text[i]) j=next[i];
		if(text[i]==pattern[j+1]) j++;
		if(j==m-1){
			free(next);
			return i-j;
		}
	}
	free(next);
	return -1
}

int main(int argc, char *argv[]) {
	
}