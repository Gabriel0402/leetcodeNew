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

bool isBalanced(TreeNode *root){
	return balanceHeight(root)>0
}

int balanceHeight(TreeNode *root){
	if(root==NULL) return 0;
	int left=balanceHeight(root->left);
	int right=balanceHeight(root->right);
	if(left<0 || right<0 ||abs(left-right)>1) return -1;
	return max(left,right)+1;
}

void flatten(TreeNode *root){
	stack<TreeNode *> s;
	if(root==NULL) return;
	s.push(root);
	while(!s.empty()){
		TreeNode *p=s.top();
		s.pop();
		if(p->right) s.push(p->right);
		if(p->left) s.push(p->left);
		p->left=NULL;
		if(!s.empty()) p->right=s.top();
	}
}

void connect(TreeLinkNode *root){
	if(root==NULL) return;
	while(root){
		TreeLinkNode *next=NULL;
		TreeNode *prev = NULL;
		for(;root;root=root->next){
			if(!next) next=root->left?root->left:root->right;
			if(root->left){
				if(prev) prev->next=root->left;
				prev=root->left;
			}
			if(root->right){
				if(prev) prev->next=root->right;
				prev=root->right;
			}
		}
		root=next;
	}
}


//recover BST
void recoverTree(TreeNode* root){
	pair<TreeNode*, TreeNode> broken;
	TreeNode *prev=NULL;
	TreeNode *cur=root;

}
int numTrees(int n){
	return BST(1,n);
}
int BST(int start, int end){
	if(start>=end) return 1;
	int res=0;
	for(int i=start;i<=end;i++){
		res+=BST(start,i-1)*BST(i+1,end);
	}
	return res;
}

vector<TreeNode *> generateTrees(int n){
	vector<TreeNode*> result;
	build(result,1,n);
	return result;
}

void build(vector<TreeNode*> &result,int nStart, int nEnd)
{
	if(nStart>nEnd) result.push_back(NULL);
	else{
		for(int =nStart;i<=nEnd;++i){
			vector<TreeNode *> left;
			build(left, nStart,i-1);
			vector<TreeNode *> right;
			build(right,i+1,nEnd);
			for(int j=0;j<left.size();++j){
				for(itn k=0;k<right.size();++k){
					TreeNode *root = new TreeNode(i);
					root->left=left[j];
					root->right=right[k];
					result.push_back(root);
				}
			}
		}
	}
}

bool isValid(TreeNode *root){
	return isValidBST(root, INT_MIN,INT_MAX);
}

bool isValidBST(root,low,high){
	if(root==NULL) retur true;
	else return root->val>low && root->val<high && isValidBST(root->left,low,root->val) && isValidBST(root->right,root->val,high);
}

TreeNode* sortedArrayToBST(vector<int>& num){
	return sortedArrayToBST(num.begin(),num.end());
}

template<typename RandomAccessIterator>
TreeNode* sortedArrayToBST(RandomAccessIterator first, RandomAccessIterator last){
	const auto length=distance(first ,last);
	if(length<=0) return NULL;
	auto mid=first+length/2;
	TreeNode* root=new TreeNode(*mid);
	root->left=sortedArrayToBST(first,mid);
	root->right=sortedArrayToBST(mid+1,last);
	return root; 
}

int minDepth(const TreeNode *root){
	return minDepth(root,false);
}

static int minDepth(const TreeNode *root, bool hasbrother){
	if(!root) return hasbrother?INT_MAX:0;

	return 1+min(minDepth(root->left,root->right!=NULL),minDepth(root->right,root->left!=NULL));
}


int maxDepth(TreeNode *root){
	uf(root==NULL) return 0;
	return max(maxDepth(rpoot->left),maxDepth(root->right))+1;
}

bool hasPathSum(TreeNode *root, int sum){
	if(root==NULL) return false;
	if(root->left == NULL && root->right==NULL) return sum==root->val;
	return hasPathSum(root->left,sum-root->val) || hasPathSum(root->right,sum-root->val);
}

vector<vector<int>> pathSum(TreeNode *root,int sum)
{
	vecotr<vector<int>> result;
	vector<int> cur;
	pathSum(root,sum,cur,result);
	return result;
}

void pathSum(TreeNode *root, int gap, vector<int> &cur, vector<vector<int>> &result){
	if(root==NULL) return;
	cur.push_back(root->val);
	if(root->left == NULL && root->right==NULL){
		if(gap==root->val) result.push_back(cur);
	}
	pathSum(root->left,gap-root->val,cur,result);
	pathSum(root->right,gap-root->val,cur,result);
	cur.pop_back();
}
