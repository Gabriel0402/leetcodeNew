class Solution {
public:
    bool isHappy(int n) {
        map<int,bool> cache;
        set<int> cycle;
        while(n!=1 && !cycle.count(n)){
            if(cache.count(n)){
                n=cache[n]?1:0;
                break;
            }
            cycle.insert(n);
            int newn=0;
            while(n>0){
                int digit=n%10;
                newn+=digit*digit;
                n/=10;
            }
            n=newn;
        }
        bool happiness=n==1;
        for(set<int>::iterator it=cycle.begin();it!=cycle.end();it++){
            cache[*it]=happiness;
        }
        return happiness;
        
    }
};