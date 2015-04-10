#include <iostream>

using namespace std;

//regular express match
bool isMatch(const char*s, const char *p){
	if(*p=='\0') return *s=='\0';
	
	if(*(p+1)!='*'){
		if(*p==*s || (*p=='.'&& *s!='\0')) 
			return isMatch(s+1,p+1);
		else return false;
	} 
	else{
		while(*p==*s||(*p=='.'&&*s!='\0')){
			if(isMatch(s,p+2)) return true; 
			s++;
		}
		return isMatch(s,p+2);
	}
} 


//wildcard matching
bool isMatching(const char *s, const char *p){
	bool star = false;
	const char *str, *ptr;
	for(str=s,ptr=p;str!='\0';str++,ptr++){
		switch(*ptr){
			case '?':
				break;
			case '*':
				star = true;
				s=str,p=ptr;
				while(*p=='*') p++;
				if(*p='\0') return true;
				str = s-1;
				ptr=p-1;
				break;
			default:
				if(*str!=*ptr){
					if(!star) return false;
					s++;
					str = s-1;
					ptr=p-1;
				}
		}
	}
	while(*ptr == '*') ptr++;
	return (*ptr=='\0');
	
}


int main(int argc, char *argv[]) {
	
}