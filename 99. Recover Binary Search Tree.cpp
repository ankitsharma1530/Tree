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
    void solve(TreeNode* curr, TreeNode*& n1, TreeNode*& n2,TreeNode*& pre)
    {
        if(curr==NULL)
        {
            return;
        }
        solve(curr->left,n1,n2,pre);
        if(pre && pre->val>curr->val)
        {
            if(n1==NULL)
            {
                n1 = pre;
            }
            n2 = curr;
        }
        pre = curr;
        solve(curr->right,n1,n2,pre);
    }
    void recoverTree(TreeNode* root) {
        TreeNode* curr = root;
        TreeNode* pre = NULL;
        TreeNode* n1  =  NULL;
        TreeNode* n2 = NULL;
        solve(curr,n1,n2,pre);
        swap(n1->val,n2->val);
    }
};
