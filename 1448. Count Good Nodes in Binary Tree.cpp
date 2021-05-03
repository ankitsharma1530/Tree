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
    int count = 0;
    void dfs(TreeNode* root, int comp)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->val>=comp)
        {
            count++;
        }
        int temp = max(comp,root->val);
        dfs(root->left,temp);
        dfs(root->right,temp);
    }
    int goodNodes(TreeNode* root) {
        dfs(root,root->val);
        return count;
    }
};

















