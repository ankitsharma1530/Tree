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
    // We know that a binary tree can be represented by an array (assume the root begins from the position with index 1 in the array). If the index of a node is i, the indices of its two children are 2*i+1 and 2*i + 2long long.
//     
    // width for every level basically mean the width of leftmost and the rightmost node in that particular level
    
    int widthOfBinaryTree(TreeNode* root) {
	if(!root)
        return 0;
	queue<pair<TreeNode*,unsigned long long int>> que;
	que.push({root, 0});
	int width = 0;
	while (que.size() != 0) {
		unsigned long long int left = que.front().second; 
        unsigned long long int right = 0;
		int size = que.size();
		while(size--){
			pair<TreeNode*,unsigned long long int> rNode = que.front();
			que.pop();
			right = rNode.second;
			if (rNode.first->left) {
				que.push({rNode.first->left, 2 * rNode.second + 1});
			}
			if (rNode.first->right) {
				que.push({rNode.first->right, 2 * rNode.second + 2});
			}
		}
		width = max(width, int(right - left + 1));
	}
	return width;
}
};
