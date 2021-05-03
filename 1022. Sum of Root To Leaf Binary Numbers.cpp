class Solution {
public:
    int ans = 0;
    int isnum(string s)
    {
        int n = 0;
        int i=0;
        for(int j=s.length()-1;j>=0;j--)
        {
            if(s[j]=='1')
            {
                n+=pow(2,i);
            }
            i++;
        }
        return n;
    }
    void solve(TreeNode* root,string s)
    {
        
        if(root==NULL)
        {
            return;
        }
        s+=to_string(root->val);
        if(root->left==NULL && root->right==NULL)
        {
            int num = isnum(s);
            ans+=num;
            return;
        }
        solve(root->left,s);
        solve(root->right,s);
        s.pop_back();
    }
    int sumRootToLeaf(TreeNode* root) {
        solve(root,"");
        return ans;
    }
};
