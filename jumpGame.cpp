class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>f(n,0);
        for(int i=1;i<n;i++){
            f[i]=max(f[i-1],nums[i-1])-1;
            if(f[i]<0) return false;
        }
        return f[n-1]>=0;
        
    }

    int jump(int a[],int n){
    	int result;
    	int last=0;
    	int cur=0;
    	for(int i=0;i<n;++i){
    		if(i>last){
    			last=cur;
    			++result;
    		}
    		cur=max(cur,i+a[i]);
    	}
    	return result;
    }
};