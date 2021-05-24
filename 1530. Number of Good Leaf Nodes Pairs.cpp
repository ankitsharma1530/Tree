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
    vector<int> dfs(TreeNode* root, int d)
    {
        if(root==NULL)
        {
            return {0};
        }
        if(root->left==NULL and root->right==NULL)
        {
            return {1};
        }
        
        vector<int>left = dfs(root->left,d);
        vector<int>right = dfs(root->right,d);
        
        // how many leafs from right and left are in the range
        for(auto& x:left)
        {
            for(auto& y:right)
            {
                if(x>0 and y>0 and x+y<=d)
                {
                    // pair has been found
                    count++;
                }
            }
        }
        vector<int>ans;
        for(auto& x:left)
        {
            if(x<d && x>0)
            {
                ans.push_back(x+1);
            }
        }
        for(auto& x:right)
        {
            if(x<d && x>0)
            {
                ans.push_back(x+1);
            }
        }
        
        return ans;
    }
    int countPairs(TreeNode* root, int distance) {
        dfs(root,distance);
        return count;
    }
};
