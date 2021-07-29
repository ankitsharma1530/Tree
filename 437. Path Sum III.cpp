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
// leetcode notes
/*
class Solution {
public:
    // O(n^2)
    int solve(TreeNode* root,int target,int sum){
        if(root==NULL){
            return 0;
        }
        sum+=root->val;
        return (sum==target)+solve(root->left,target,sum)+solve(root->right,target,sum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        // the basic idea code is in leetcode notes
        if(!root){
            return 0;
        }
        return solve(root,targetSum,0)+pathSum(root->left,targetSum)+pathSum(root->right,targetSum);
    }
};

*/

unordered_map<int,int>m;

class Solution {
public:
    
    void solve(TreeNode* root,int curr_sum,int &res,int sum)
    {
        if(!root) return;
        curr_sum+=root->val;
        if(curr_sum==sum) res++;
        res+=m[curr_sum-sum];
        m[curr_sum]++;
        solve(root->left, curr_sum, res, sum);
        solve(root->right, curr_sum, res, sum);
        m[curr_sum]--;
    }
    
    int pathSum(TreeNode* root, int sum) {
        m.clear();
        int res=0;
        solve(root,0,res,sum); return res;
    }
};
