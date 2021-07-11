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
    int ans = 0;
    int dfs(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int l = dfs(root->left);
        int r = dfs(root->right);
        // operation
        //    4
        //  1   1
        int x = 0;
        int y = 0;
        // this operation is all about this question
        if(root->left and root->left->val==root->val){
            x+=l+1;
        }
        if(root->right and root->right->val==root->val){
            y+=r+1;
        }
        
        // similar logic as -> Binary Tree Maximum Path Sum

        ans = max(ans,x+y);
        return max(x,y);
        
    }
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
