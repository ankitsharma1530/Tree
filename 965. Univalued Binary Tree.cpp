class Solution {
public:
    bool solve(TreeNode* root, int c)
    {
        if(root==NULL)
        {
            return true;
        }
        if(root->val!=c)
        {
            return false;
        }
        return solve(root->left,c)&&solve(root->right,c);
    }
    bool isUnivalTree(TreeNode* root) {
        if(root==NULL)
        {
            return true;
        }
        int c = root->val;
        return solve(root,c);
    }
};
