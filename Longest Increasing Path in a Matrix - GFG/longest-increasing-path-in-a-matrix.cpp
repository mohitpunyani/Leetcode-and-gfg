//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


class Solution {
    public:
    
    int dfs(int i, int j, int &n, int &m,int prev,vector<vector<int>>& matrix,vector<vector<int>>&visited)
    {
        if(i<0 or j<0 or i>=n or j>=m or matrix[i][j]<=prev or visited[i][j]==true)
        return 0;
        
        int ans=0;
        
        visited[i][j]=true;
        
        int curr=matrix[i][j];
        
        int a = dfs(i+1,j,n,m,curr,matrix,visited);
        int b = dfs(i-1,j,n,m,curr,matrix,visited);
        int c = dfs(i,j+1,n,m,curr,matrix,visited);
        int d = dfs(i,j-1,n,m,curr,matrix,visited);
        
        ans=1+max({a,b,c,d});
        
        visited[i][j]=0; // BACKTRACK
        
        return ans;
    }
    
int topdowndp(int i, int j, int &n, int &m,int prev,vector<vector<int>>& matrix,vector<vector<int>>&visited,vector<vector<int>>&dp)
    {
        if(i<0 or j<0 or i>=n or j>=m or matrix[i][j]<=prev or visited[i][j]==true)
        return 0;
        
        int ans=0;
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        visited[i][j]=true;
        
        int curr=matrix[i][j];
        
        int a =topdowndp(i+1,j,n,m,curr,matrix,visited,dp);
        int b =topdowndp(i-1,j,n,m,curr,matrix,visited,dp);
        int c =topdowndp(i,j+1,n,m,curr,matrix,visited,dp);
        int d =topdowndp(i,j-1,n,m,curr,matrix,visited,dp);
        
        ans=1+max({a,b,c,d});
        
        visited[i][j]=0; // BACKTRACK
        
        dp[i][j]=ans;
        
        return dp[i][j];
    
    }
    
    
    int longestIncreasingPath(vector<vector<int>>& matrix, int n, int m) 
    {
        int res=1;
        
        // DFS QUESTION (DEKHTE HI PATA CHAL GAYA)
        
        int prev=INT_MIN;
        
        // vector<vector<int>>visited(n,vector<int>(m,0));
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++){
        //         res=max(res,dfs(i,j,n,m,prev,matrix,visited));
        //     }
        // }
        // return res;
        
        
        // DP TOPDOWNDP
        
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                res=max(res,topdowndp(i,j,n,m,prev,matrix,visited,dp));
            }
        }
        return res;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        cout << obj.longestIncreasingPath(matrix, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends