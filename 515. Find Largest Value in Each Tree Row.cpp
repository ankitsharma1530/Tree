class Solution {
public:
    void preorder(TreeNode* root, int depth, vector<int>& max_val){
        if(root == NULL){
            return;
        }
        
        if(max_val.size() > depth){
            max_val[depth] = max(max_val[depth], root->val);
        }else{
            max_val.push_back(root->val);
        }
        preorder(root->left, depth+1, max_val);
        preorder(root->right, depth+1, max_val);
    }
    
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        preorder(root, 0, ans);
        return ans;
    }
};
