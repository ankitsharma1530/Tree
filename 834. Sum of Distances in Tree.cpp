class Solution {
public:
    // article -> https://leetcode.com/problems/sum-of-distances-in-tree/discuss/1308366/C%2B%2B-solution-using-dfs-with-explanation-O(N)-time-complexity
    
    // refer the above article for O(n)
    
    
    void dfs(vector<vector<int>>&adj,
             int node, int par,vector<int>& count, vector<int>& res){
        
        for(auto x:adj[node]){
            if(x==par){
                continue;
            }
            dfs(adj,x,node,count,res);
            count[node]+=count[x];
            res[node] += count[x]+res[x];
        }
        count[node]+=1;
    }
    
    void dfs2(vector<vector<int>>&adj,
             int node, int par,vector<int>& count, vector<int>& res,int n){
        
        for(auto x:adj[node]){
            if(x==par){
                continue;
            }
            res[x] = res[node]-count[x]+n-count[x];
            dfs2(adj,x,node,count,res,n);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        // O(n^2) approach in leetcode notes.
        vector<vector<int>>adj(n);
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int>count(n,0);
        vector<int>res(n,0);
        dfs(adj,0,-1,count,res);
        dfs2(adj,0,-1,count,res,n);
        return res;
    }
};
