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
    void solve(unordered_map<TreeNode*,TreeNode*>& ump, TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left==NULL && root->right==NULL)
        {
            return;
        }
        if(root->left)
        {
            if(root->left->left)
            {
                ump[root->left->left] = root;
            }
            if(root->left->right)
            {
                ump[root->left->right] =root;
            }
        }
        if(root->right)
        {
        if(root->right->right)
        {
            ump[root->right->right] =root;
        }
        if(root->right->left)
        {
            ump[root->right->left] =root;
        }
        }
        
        
        solve(ump,root->left);
        solve(ump,root->right);
    }
    int sumEvenGrandparent(TreeNode* root) {
        unordered_map<TreeNode*,TreeNode*>ump;
        solve(ump,root);
        int res = 0;
        for(auto& x:ump)
        {
            if(x.second->val%2==0)
            {
                res+=x.first->val;
            }
        }
        return res;
    }
};
