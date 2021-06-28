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

// O(n^2) solution is in leetcode notes-> check that first
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        // O(n) solution with using stack
        
        // This is also called a Cartesian Tree. One interesting property is that if we do           // an in-order traversal, we get the array back which we used to create it.
        
        // so we can use iterative inorder traversal for this question
        // there will be little updates
        
        stack<TreeNode*> stk;
        for (int num : nums) {
            TreeNode* node = new TreeNode(num);
            while (!stk.empty() && stk.top() -> val < node -> val) {
                node -> left = stk.top();
                stk.pop();
            }
            if (!stk.empty()) {
                stk.top() -> right = node;
            }
            stk.push(node);
        }
        while (stk.size() > 1) {
            stk.pop();
        }
        return stk.top();
    }
};
