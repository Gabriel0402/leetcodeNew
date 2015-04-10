#include <iostream>

using namespace std;

bool isNumber(char const *s){
	char* endptr;
	strtod(s,&endptr);
	if(endptr==s) return false;
	for(;*endptr;++endptr){
		if(!isspace(*endptr)) return false;
		
	}
	return true;
}
int main(int argc, char *argv[]) {
	
}