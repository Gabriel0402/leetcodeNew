#include <iostream>

class Solution {
public:
    void rotate(int nums[], int n, int k) {
        if(n<=1) return;
        k=k%n;
        if(k<=0) return;
        reverse(nums,0,n-k-1); 
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-1);
        
    } 
    
    void reverse(int nums[],int left,int right){
        for(int i=left, j=right; i<j;++i,--j){
            swap(nums[i],nums[j]);
        }
    }
};