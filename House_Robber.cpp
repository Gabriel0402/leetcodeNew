#include <iostream>

using namespace std;

class Solution {
public:
    int rob(vector<int> &num) {
        if(num.size()==0) return 0;
        num[1]=max(num[0],num[1]);
        for(int i=2;i<num.size();i++){
            num[i]=max(num[i-1],num[i-2]+num[i]);
        }
        return num[num.size()-1];
    }
};


int main(int argc, char *argv[]) {
	
}