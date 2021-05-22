/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// class Solution {
// public:
//     bool flag = true;
//     TreeNode* res;
//     void solve(TreeNode* cloned, TreeNode* target)
//     {
//         if(flag==false)
//         {
//             return;
//         }
//         if(cloned == NULL)
//         {
//             return;
//         }
//         solve(cloned->left,target);
//         solve(cloned->right,target);
//         if(cloned->val==target->val)
//         {
//             flag = false;
//             res = cloned;
//             // return cloned;
            
//         }
//         // return NULL;
        
//     }
//     TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
//         solve(cloned,target);
//         return res;
//     }
// };

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* ans = nullptr;
        if(!original) return nullptr;
        if(original->val == target->val)
        return cloned;
        else 
            ans = getTargetCopy(original->left , cloned->left , target);
        if(ans)
            return ans;
        ans = getTargetCopy(original->right , cloned->right , target);
        original->left = nullptr;
        original->right = nullptr;
        cloned->left  = nullptr;
        cloned->right = nullptr;
        return ans;
        
        
    }
};
