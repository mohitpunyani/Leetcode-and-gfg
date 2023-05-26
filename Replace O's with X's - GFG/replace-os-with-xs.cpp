//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// class Solution{
// public:

// void dfs(vector<vector<int>>&visited,vector<vector<char>>&mat,int i,int j,int row,int col)
// {
//     if(i<0 or j<0 or i>=row or j>=col or mat[i][j]=='O' or mat[i][j]!='O' )
//     {
//         return ;
//     }
//         if(mat[i][j]=='O') mat[i][j]='B';

//         // visited[i][j]=1;
//         // mat[i][j]='B';
//         dfs(visited,mat,i+1,j,row,col);
//         dfs(visited,mat,i-1,j,row,col);
//         dfs(visited,mat,i,j+1,row,col);
//         dfs(visited,mat,i,j-1,row,col);
//         return ;
// }
//     vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
//     {
//         // code here
        
//         // dfs solution(THIS IS A QUESTION OF BOUNDARY DFS)
        
//         // WE EXCLUDE THE BOUNDARY 
        
// //NOTE -> HERE WE THINK COUNTER (ULTA) APPROACH BOUNDARY SE CHALNA START KARENGE OR YOU CAN SAY THAT KI BOUNDARY 
// // PAR DFSLAGAY

// // BOUNDARY PAR JITNI BHI ZEROS HONGI WOH KABHI BHI DFS ME CHANGE NAHI HO SAKTI

// // VERY EASY QUESTION 


// vector<vector<int>>visited(n,vector<int>(m,0));

// for(int i=0;i<n;i++)
// {
//     for(int j=0;j<m;j++)
//     {
//         if((i==0 or j==0 or i==n-1 or j==m-1) && mat[i][j]=='O')
//         {
//             // call for dfs
//             dfs(visited,mat,i,j,n,m);
//         }
//     }
// }
// for(int i=0;i<n;i++){
//     for(int j=0;j<m;j++){
//         if(mat[i][j]=='O'){
//             mat[i][j]='X';
//         }
//         if(mat[i][j]=='B'){
//             mat[i][j]='O';
//         }
//     }
    
// }
// return mat;
        
//     }
// };

class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& board){
    if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!='O') return;
    // if(board[i][j]=='O') 
    board[i][j]='#';
    dfs(i+1,j,board);
    dfs(i,j+1,board);
    dfs(i-1,j,board);
    dfs(i,j-1,board);  
}
    
    
    vector<vector<char>> fill(int n,int m,vector<vector<char>>& mat)
    {
        vector<vector<char>>board=mat;
        m=board.size(),n=board[0].size();
       for(int i=0;i<m;i++)
       {
           for(int j=0;j<n;j++){
               if((i==0 || i==m-1 || j==0 || j==n-1) && board[i][j]=='O'){
                   dfs(i,j,board);
               }
           }
       } 
         for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
               if(board[i][j]=='O') board[i][j]='X';
               if(board[i][j]=='#') board[i][j]='O';
               }
           }
           return board;
       }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends