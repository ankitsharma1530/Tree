/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> res;
	TreeNode* dfs(TreeNode* root,unordered_set<int>& table){
		if(not root) return root;
		root->left=dfs(root->left,table);
		root->right=dfs(root->right,table);
		if(table.find(root->val)!=table.end()){
			if(root->left){
				res.push_back(root->left);
			}
			if(root->right){
				res.push_back(root->right);
			}
			return NULL;
		}
		else return root;
	}
	vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
		unordered_set<int> table(to_delete.begin(),to_delete.end());
		dfs(root,table);
		if(table.find(root->val)==table.end()){
			res.push_back(root);
		}
		return res;

	}
};
