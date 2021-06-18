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
    TreeNode* prev=nullptr; int minV = INT_MAX;
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return minV;
    }
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        if(prev) minV = min(minV, abs(prev->val - root->val));
        prev = root;
        inorder(root->right);
    }
};
