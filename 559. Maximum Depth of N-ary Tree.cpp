// dfs
class Solution {
public:
    int maxDepth(Node* root) {
        if(root==NULL)
            return 0;
        int res=0;
        for(auto child: root->children)
            res= max(res, maxDepth(child));
        return 1+res;
    }
};


// bfs
class Solution {
public:
    int maxDepth(Node* root) {
        int res = 0;
        if(root==NULL)
        {
            return 0;
        }
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            res++;
            int size = q.size();
            while(size--)
            {
                Node* curr = q.front();
                q.pop();
                
                for(int i=0;i<curr->children.size();i++)
                {   
                    if(curr->children[i]!=nullptr)
                    q.push(curr->children[i]);
                }
            }
        }
        
        return res;
    }
};
