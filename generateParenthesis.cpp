vector<string> generateParemthesis(int n){
	if(n==0) return vector<string>(1,"");
	if(n==1) return vector<string>(1,"()");
	vector<string> result;
	for(int i=0;i<n;++i){
		for(auto inner:generateParemthesis(i))
			for(auto outer:generateParemthesis(n-1-i))
				result.push_back("("+inner+")"+outer);
	}
	return result;
}