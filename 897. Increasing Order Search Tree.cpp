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
    TreeNode* node;
    void inorder(TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }
        inorder(root->left);
        
        root->left = NULL;
        node->right = root;
        
        node = node->right;
        inorder(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* res = new TreeNode(-1);
        node = res;
        inorder(root);
        return res->right;
    }
};
