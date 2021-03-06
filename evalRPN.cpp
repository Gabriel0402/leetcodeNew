int evalRPN(vector<string> &tokens){
	stack<string> s;
	for(auto token:tokens){
		if(!is_operator(token)){
			s.push(token);
		}
		else{
			int y=stoi(s.top());
			s.pop();
			int x=stoi(s.top());
			s.pop();
			if(token[0] =='+')  x+=y;
			else if(token[0]=='-') x-=y;
			else if(token[0]=='*') x*=y;
			else if(token[0]=='/') x/=y
			s.push(to_string(x));
		}
	}
	 return stoi(s.top());

}

bool is_operator(const string &op){
	return op.size()==1 && string("+-*/").find(op) !=string::npos;
}