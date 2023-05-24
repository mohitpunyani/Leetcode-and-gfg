//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
//   void dfs(vector<vector<char>>&grid,int i , int j)
//   {
//       if(i<0 || j<0 || i>=grid.size()  || j>=grid[0].size() || grid[i][j]=='0')
//       {
//           return ;
//       }
        
//         // call is 8 directions
        
//         grid[i][j]='0';  // reset to zero because this is already included or visited.
        
//         //  mark as visited for visited mark make it to zero
        
        
        
//         dfs(grid,i-1,j);
//         dfs(grid,i+1,j);
//         dfs(grid,i,j-1);
//         dfs(grid,i,j+1);
//         dfs(grid,i-1,j+1);
//         dfs(grid,i+1,j-1);
//         dfs(grid,i-1,j-1);
//         dfs(grid,i+1,j+1);
//         return ;
//   }
  
  
       int x[8]={0,-1,-1,-1,0,1,1,1};
       int y[8]={-1,-1,0,1,1,1,0,-1};
       
  void dfs_efficient(vector<vector<int>>&visited,vector<vector<char>>&grid,int i,int j,int n,int m)
  {
      // standard method
      
     
       
      // make a vector for 8 directions
      
      visited[i][j]=1;
      for(int k=0;k<8;k++)
      {
          int row=i+x[k];
          int col=j+y[k];
          
          if(row>=0 && row<n && col>=0 && col<m && visited[row][col]!=1 &&
            grid[row][col]=='1'){
            dfs_efficient(visited,grid,row,col,n,m);
            }
      }
    //   return ;
  }

    // Function to find the number of islands.
    
    
    int numIslands(vector<vector<char>>& grid) 
    {
        
    //     // Code here
        
    //     // no. of connected components
        
    //     // USING DFS
        
    //     int islands=0;
    //     for(int i=0;i<grid.size();i++){
    //         for(int j=0;j<grid[i].size();j++)
    //         {
    //             if(grid[i][j]=='1')
    //             {
    //                 // if it is land than we have to proceed further
                    
    //                 dfs(grid,i,j);
    //                 islands++;
                    
    //             }
                
    //         }
            
    //     }
    //     return islands;
        
        // EFFICIENT WAY TO WRITE DFS (IT IS DEVELOPED BY ABOVE DFS APPROACH)
        
        
        // making a visited vector having n rows and m columns
        
        int islands=0;
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && visited[i][j]==0)
                {
                    islands++;
                    dfs_efficient(visited,grid,i,j,n,m);
                }
            }
            
        }
        return islands;
        
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends