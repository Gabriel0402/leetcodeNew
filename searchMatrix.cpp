bool searchMatrix(const vector<vector<int>> &matrix,int target){
	if(matrix.empty()) return false;
	const size_t m=matrix.size();
	const size_t n=matrix[0].size();
	int first = 0;
	int last = m*n;
	while(first<last){
		int mid=fist+(last-first)/2;
		int val=matrix[mid/n][mid%n];
		if(value==target) return true;
		else if(value<target) first=mid+1;
		else last=mid;
	}
	return false;
}