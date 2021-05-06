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
class BSTIterator {
public:
    
    // for inorder we need stack
    stack<TreeNode*>st;
    void push_all(TreeNode* root)
    {
        
        while(root!=NULL)
        {
            st.push(root);
            root = root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        // this will push the root and all the left nodes to it
        push_all(root);
    }
    
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        if(temp->right!=NULL)
        {
            push_all(temp->right);
        }
        return temp->val;
    }
    
    bool hasNext() {
        if(!st.empty())
        {
            return true;
        }
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
