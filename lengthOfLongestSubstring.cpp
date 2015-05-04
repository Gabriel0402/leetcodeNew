int lenghOfLongestSubstring(string s){
	const int ASCII_MAX=26;
	int last[ASCII_MAX];
	int start;
	fill(last,last+ASCII_MAX,-1);
	int max_len=0;
	for(int i=0;i<s.size();i++){
		if(last[s[i]-'a']>=start){
			max_len=max(i-start,max_len);
			start=last[s[i]-'a']+1;
		}
		last[s[i]-'a']=i;
	}
	return max((int)s.size()-start,max_len);
}