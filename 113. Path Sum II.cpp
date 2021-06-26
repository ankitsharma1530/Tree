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

// code with passing the ans with refrence is present in leetcode notes
class Solution {
public:
    // targetsum -> ts
    // curr_sum -> s
    
    // time complexity -> O(n) as we are visiting every nodes
    void solve(vector<vector<int>>& res, vector<int> ans, TreeNode* root,int ts,int s){
        if(root==NULL){
            return;
        }
        ans.push_back(root->val);
        s+=root->val;
       
        if(root->left==NULL and root->right==NULL){
            if(s==ts){
                res.push_back(ans);
            }
            return;
        }
        solve(res,ans,root->left,ts,s);
        solve(res,ans,root->right,ts,s);
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>res;
        vector<int>ans;
        solve(res,ans,root,targetSum,0);
        return res;
    }
};
