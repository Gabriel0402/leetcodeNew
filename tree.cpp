struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};


vector<int> preorderTraversal(TreeNode *root){
	vector<int> res;
	stack<TreeNode *>s;
	const TreeNode *p;
	p=root;
	if(p!=NULL) s.push(p);
	while(!s,empty()){
		p=s.top();
		s.pop();
		result.push_back(p->val);
		if(p->right!=NULL) s.push(p->right);
		if(p->left!=NULL) s.push(p->left);
	}
	return res;
}
 
vector<int> inorderTraversal(TreeNode *root){
	vector<int> result;
	const TreeNode *p=root;
	stack<TreeNode*> s;
	while(!s.empty() && p!=NULL){
		if(p!=NULL){
			s.push(p);
			p=p->left;
		}else{
			p=s.top();
			s.pop();
			result.push_back(p->val);
			p=p->right;
		}
	}
	return result; 
}

vector<int> postorderTraversal(TreeNode *root){
	vector<int> result;
	const TreeNode *p, *q;
	stack<const TreeNode *> s;
	p=root;
	do{
		while(p!=NULL){
			s.push(p);
			p=p->left;
		}
		q=NULL;
		while(!s.empty()){
			p=s.top();
			s.pop();
			if(p->right==q){
				result.push_back(p->val);
				q=p;
			}else{
				s.push(p);
				p=p->right;
				break;
			}
		}

	}while(!s,empty();)
	return result;
}

vector<vecotr<int>> levelOrder(TreeNode *root){
	vector<vector<int>> result;
	traverse(root,1,result);
	return result;
}

vector<vecotr<int>> levelOrder(TreeNode *root){
	vector<vector<int>> result;
	traverse(root,1,result);
	reverse(result.begin(),result.end());
	return result;
}

void traverse(TreeNode *root, size_t level, vector<vector<int>> &result){
	if(!root) return;
	if(level>result.size()) result.push_back (vector<int>)
	result[level-1].push_back(root->val);
	traverse(root->left,level+1,result);
	traverse(root->right,level+1,result);
}

vector<vector<int>> zigzigLevelOrder(TreeNode *root){
	vector<vector<int>> result;
	if(root==NULL) return result;

	queue<TreeNode *> q;
	bool left_to_right = true;
	vector<int> level;

	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		TreeNode *cur=q.front();
		q.pop();
		if(cur) {
			level.push_back(cur->val);
			if(cur->left) q.push(cur->left);
			if(cur->right) q.push(cur->right);
		}else{
			if(left_to_right){
				result.push_back(level);
			}else{
				reverse(level.begin(),level.end());
				result.push_back(level); 
			}
			level.clear();
			level_to_right=!level_to_right;

		}
	}
}

bool isSameTree(TreeNode *p,TreeNode *q){
	if(!p && !q) return true;
	if(!p||!q) return false;
	return p->val==q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
}

bool isSymmetric(TreeNode *root){
	if(!root) return true;
	stack<TreeNode *>s;
	s.push(root->left);
	s.push(root->right);
	while(!s.empty()){
		TreeNode *p=s.top();
		s.pop();
		TreeNode *q=s.top();
		s.pop();
		if(!p && !q) continue;
		if(!p || !q) return false;
		if(p->val!=q->val) return false;
		s.push(p->left);
		s.push(q->right);
		s.push(p->right);
		s.push(q->left); 

	}
	return true;
}
