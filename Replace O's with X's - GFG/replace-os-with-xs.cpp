//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    
// void dfs(vector<vector<char>>&mat,int i,int j,int row,int col)
// {
//     if(i<0 or j<0 or i>=row or j>=col  or mat[i][j]=='X' or mat[i][j]=='B' )
//     {
//         return ;
//     }
//         mat[i][j]='B';
//         dfs(mat,i+1,j,row,col);
//         dfs(mat,i-1,j,row,col);
//         dfs(mat,i,j+1,row,col);
//         dfs(mat,i,j-1,row,col);
//         return ;
// }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        
        // dfs solution(THIS IS A QUESTION OF BOUNDARY DFS)
        
        // WE EXCLUDE THE BOUNDARY 
        
//NOTE -> HERE WE THINK COUNTER (ULTA) APPROACH BOUNDARY SE CHALNA START KARENGE OR YOU CAN SAY THAT KI BOUNDARY 
// PAR DFSLAGAY

// BOUNDARY PAR JITNI BHI ZEROS HONGI WOH KABHI BHI DFS ME CHANGE NAHI HO SAKTI

// VERY EASY QUESTION 




// for(int i=0;i<n;i++)
// {
//     for(int j=0;j<m;j++)
//     {
//         if((i==0 or j==0 or i==n-1 or j==m-1) && mat[i][j]=='O')
//         {
//             // call for dfs
//             dfs(mat,i,j,n,m);
//         }
//         else{
//             continue;
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
        
        
        // USING BFS
        
        
              vector<vector<char>> ans = mat;
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(ans[i][j]=='O'){
                        vis[i][j] = 1;
                        q.push({i,j});
                    }
                }
            }
        }
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            vector<int> dx = {-1,0,1,0};
            vector<int> dy = {0,-1,0,1};
            for(int i=0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && mat[nx][ny]=='O'){
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ans[i][j]=='O' && !vis[i][j]){
                    ans[i][j] = 'X';
                }
            }
        }
        return ans;
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