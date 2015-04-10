#include <iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t count = sizeof(n)*8;
        uint32_t reverse_n = 0;
        for(int i=0;i<count;i++){
            if(n&(1<<i)){
                reverse_n |=(1<<(count-1-i));
            }
        }
        return reverse_n;
    }
};

int main(int argc, char *argv[]) {
	
}