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
    int findSecondMinimumValue(TreeNode* root) 
    {
        if(root==NULL)
            return -1;
        long ans=LONG_MAX;
        
        queue<TreeNode *>q;
        q.push(root);
        
        while(!q.empty())
        {
            int l=q.size();
            
            for(int i=0;i<l;i++)
            {
               TreeNode *temp=q.front();
                q.pop();
                
                if(temp->val>root->val)
				
                    if(ans>temp->val)  //to get min value 
                        ans=temp->val;
                
                if(temp->left )
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                
            }
        }
         if(ans!=LONG_MAX)
               return ans;
        return -1;
      
        
    }
};
