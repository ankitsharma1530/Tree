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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root==NULL)
        {
            return NULL;
        }
        
        // post order traversal
        root->left = trimBST(root->left,low,high);
        root->right = trimBST(root->right,low,high);
        
        // these are the cases for the out of range
        if(root->val<low)
        {
            TreeNode* temp = root->right;
            // delete root;
            return temp;
        }
        if(root->val>high)
        {
            TreeNode* temp = root->left;
            // delete root;
            return temp;
        }
        
        // when we are in range
        return root;
    }
};
