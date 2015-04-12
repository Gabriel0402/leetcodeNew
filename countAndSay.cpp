#include <iostream>

using namespace std;

string countAndSay(int n){
	string str="1";
	for(int i=1;i<n;++i){
		string tmp;
		int count=1;
		char ch = str[0];
		for(int j=0;j<str.size();j++){
			if(str[j]==ch) ++count;
			else{
				tmp.insert(tmp.end(),char(count+'0'));
				tmp.insert(tmp.end(),ch);
			   ch=str[j];
				count=1;
			}
		}
		tmp.insert(tmp.end(),char(count+'0'));
		tmp.insert(tmp.end(),ch);
		str=tmp;
	}
	return str;
}
int main(int argc, char *argv[]) {
	
}