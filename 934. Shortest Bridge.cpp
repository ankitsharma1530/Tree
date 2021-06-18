class Solution {
public:
    queue<pair<int,int>>q;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,-1,1};
    // this is the function to mark whole islands
    //then from each and every point of the island we will move towards the other one
    void solve(vector<vector<int>>& A,int i, int j){
        
        A[i][j] = 2;
        q.push(make_pair(i,j));
        for(int ii=0;ii<4;ii++){
            int x = i+dx[ii];
            int y = j+dy[ii];
            if(x>=0 and x<A.size() and y>=0 and y<A[0].size()){
                if(A[x][y]==1){
                    solve(A,x,y);
                }
            }
        }
    }
    int shortestBridge(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();
        int flag = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(A[i][j]==1){
                    solve(A,i,j);
                    flag = 1;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        int res = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                pair<int,int>temp = q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int x = temp.first+dx[i];
                    int y = temp.second+dy[i];
                    if(x>=0 and x<n and y>=0 and y<m){
                        if(A[x][y]==1){
                            return res;
                        }
                        else if(A[x][y]==0){
                                A[x][y]=2;
                                q.push(make_pair(x,y));
                        }
                    }
                    
                }
            }
            res++;
        }
        return -1;
    }
};
