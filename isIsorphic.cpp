class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> map;
        unordered_map<char,char> map1;
        for(int i=0;i<s.size();i++){
            if(map.find(s[i])==map.end() && map1.find(t[i])==map1.end()){
                map[s[i]]=t[i];
                map1[t[i]]=s[i];
            }
            else{
                if(map[s[i]]!=t[i]||map1[t[i]]!=s[i]) return false;
            }
        }
    }
};