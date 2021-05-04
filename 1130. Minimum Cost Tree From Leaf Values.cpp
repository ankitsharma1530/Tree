class Solution {
public:
    int dp[41][41] ;
    int solve(vector<int>&arr , int start, int end)
    {
        // if i am having start==end , that means i will have only one node in that range
        // that node is basically a leaf node
        // whenever the starting and ending of the range are equals then the SINGLE node that is..
        // ..present in between them is LEAF node
        
        // as we know-
        /*
        The value of each non-leaf node is equal to the product of the largest leaf value in its left         and right subtree respectively.
        So for the leaf node left and right node are NULL
        thats why the product can be zero 
        Hence we return zero :D
        */
        if(start==end) 
        {
            return 0;
        }
        if(dp[start][end]!=-1)
        {
            return dp[start][end];
        }
        int ans = INT_MAX ;
        
        /*
        now we will try partiton from each and every place
        like arr[] = [2,3,4] , so we will do partition as-:
                       . .                  ( . == partition)
        as for n numbers we can do n-1 partitions 
        thats why our loops will iterate from  (start to end(not inclusive))
        */
        for(int j=start;j<end;j++)
        {
            // left partition
            // from start to j
            int l = solve(arr,start,j);
            int r = solve(arr,j+1,end);
            // this max_element will find the maximum leaf node value in the left and the right                   //partition
            ans = min(ans,l+r+*max_element(arr.begin()+start,arr.begin()+j+1) * *max_element(arr.begin()+j+1,arr.begin()+end+1));
            
        }
        dp[start][end] = ans;
        return dp[start][end];
        
    }
    int mctFromLeafValues(vector<int>& arr) {
        memset(dp,-1,sizeof(dp));
        return solve(arr,0,arr.size()-1);
    }
};
