/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root==NULL) return result;
        queue<TreeNode *> current,next;
        current.push(root);
        result.push_back(root->val);
        while(!current.empty()){
            while(!current.empty()){
                TreeNode *tmp=current.front();
                current.pop();
                if(tmp->left) next.push(tmp->left);
                if(tmp->right) next.push(tmp->right);
            }
            if(!next.empty()) result.push_back(next.back()->val);
            swap(current,next);
        }
        return result;
        
    }
};