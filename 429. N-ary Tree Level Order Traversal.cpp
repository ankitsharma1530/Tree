/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>res;
        if(root==NULL)
        {
            return res;
        }
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            vector<int>ans;
            int size = q.size();
            while(size--)
            {
                Node* curr = q.front();
                ans.push_back(curr->val);
                q.pop();
                
                for(int i=0;i<curr->children.size();i++)
                {   
                    if(curr->children[i]!=nullptr)
                    {
                    q.push(curr->children[i]);
                    
                    }
                    
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};
