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
    TreeNode* lca(TreeNode* root, TreeNode* t1, TreeNode* t2)
    {
        if(root==NULL)
        {
            return NULL;
        }
        if(root==t1 || root==t2)
        {
            return root;
        }
        TreeNode* l = lca(root->left,t1,t2);
        TreeNode* r = lca(root->right,t1,t2);
        // this means the node P Q are not present in both left and right sub trees
        if(l==NULL && r==NULL)
        {
            return NULL;
        }
        // when ever both are not NULL then that root node is the LCA of our P Q
        if(l && r)
        {
            return root;
        }
        if(!l)
        {
            return r;
        }
        return l;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* t1 = NULL;
        TreeNode* t2 = NULL;
        while(!q.empty())
        {
            int size = q.size();
            bool flag = false;
            vector<TreeNode*>v;
            while(size--)
            {
                TreeNode* curr = q.front();
                q.pop();
                v.push_back(curr);
                if(curr->left)
                {
                    q.push(curr->left);
                    flag= true;
                }
                if(curr->right)
                {
                    q.push(curr->right);
                    flag= true;
                }
            }
            if(flag==false)
            {
                t1 = v[0];
                t2 = v[v.size()-1];
            }
            
        }
        if(t1!=NULL && t2==NULL)
        {
            return t1;
        }
        if(t1==nullptr && t2!=nullptr)
        {
            return t2;
        }
        return lca(root,t1,t2);
    }
};
