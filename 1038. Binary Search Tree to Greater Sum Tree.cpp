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
    int sum = 0;
    void sum_node(TreeNode* temp)
    {
        if(temp==NULL)
        {
            return;
        }
        sum_node(temp->left);
        sum_node(temp->right);
        sum+=temp->val;
        
    }
    void dfs(TreeNode* node,int& x)
    {
        if(node==NULL)
        {
            return;
        }
        dfs(node->left,x);
        // operations
        int y = node->val;
        node->val = sum-x;
        x=x+y;
        dfs(node->right,x);
    }
    TreeNode* bstToGst(TreeNode* root) {
        TreeNode* temp = root;
        sum_node(temp);
        TreeNode* node = root;
        int x= 0;
        dfs(node,x);
        return root;
    }
};
