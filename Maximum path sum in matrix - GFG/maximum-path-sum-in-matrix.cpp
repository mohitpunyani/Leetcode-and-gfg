//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

int recursive(int N,vector<vector<int>>&Matrix,int i,int j)
{
    if(i>=N or j>=N or i<0 or j<0)
    {
        return 0;
    }
    // if(i==Matrix.size()){
    //     return Matrix[i][j];
    // }
    int ans=INT_MIN;
    int path_1=Matrix[i][j]+recursive(N,Matrix,i+1,j);
    int path_2=Matrix[i][j]+recursive(N,Matrix,i+1,j-1);
    int path_3=Matrix[i][j]+recursive(N,Matrix,i+1,j+1);
    
    ans=max({path_1,path_2,path_3});
    return ans;
}

int topdowndp(int N,vector<vector<int>>&Matrix,int i,int j,vector<vector<int>>&dp)
{
    if(i>=N or j>=N or i<0 or j<0)
    {
        return 0;
    }
    
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans=INT_MIN;
    int path_1=Matrix[i][j]+topdowndp(N,Matrix,i+1,j,dp);
    int path_2=Matrix[i][j]+topdowndp(N,Matrix,i+1,j-1,dp);
    int path_3=Matrix[i][j]+topdowndp(N,Matrix,i+1,j+1,dp);
    
    ans=max({path_1,path_2,path_3});
    dp[i][j]=ans;
    return dp[i][j];
}

// int bottomupdp(int N,vector<vector<int>>&Matrix,int i,int j,vector<vector<int>>&dp)
// {
  
   
//     vector<vector<int>>dp(N+1,vector<int>(N+1,0));
    
//     for(int i=N-1;i>=0;i--){
//         for(int j=N-1;j>=0;j--)
//         {
//             int ans=INT_MIN;
//             int path_1=Matrix[i][j]+dp[i+1][j];
//             int path_2=Matrix[i][j]+dp[i+1][j-1];
//             int path_3=Matrix[i][j]+dp[i+1][j+1];
            
//         }
//     }
//     return dp[0][0];
}
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        
        // recursive
        
        // int temp=0;
        // for(int col=0;col<N;col++)
        // {
        //     temp=max(temp,recursive(N,Matrix,0,col));
            
        // }
        
        
        // TOPDOWNDP
        
        vector<vector<int>>dp(N+1,vector<int>(N+1,-1));
        int temp=0;
        for(int col=0;col<N;col++)
        {
            temp=max(temp,topdowndp(N,Matrix,0,col,dp));
            
        }
        return temp;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends