class Solution {
public:
    // int count = 0;
    int dfs(TreeNode* root, int& count)
    {
        if(root==NULL)
        {
            return 0;
        }
        int l = dfs(root->left,count);
        int r = dfs(root->right,count);
        count+=abs(l)+abs(r);
        return root->val+l+r-1;
    }
    int distributeCoins(TreeNode* root) {
        // [[1,1],[2,0],[3,0],[4,3]]
        int count = 0;
        dfs(root,count);
        return count;    
    }
};
