//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    
    // for understand this dfs you have to dry run 
    
    // NOTE ->  THIS RECURSIVE APPROACH YOU CAN UNDERSTAND USING PEN AND PAPER OR USING DRY RUN 
    
    // NOTE -> WE USE TIME VARIABLE OR TIME +1 SO THAT WE DON'T REACH THAT NODE AGAIN AND AGAIN
    
    
//     void dfs(vector<vector<int>>&grid,int i,int j,int rows,int cols,int time)
//     {
//         // IF WE FIND EMPTY CELL THAN WE HAVE TO RETURN 
        
//     if(i<0 || j<0 || i>=rows || j>=cols || grid[i][j]==0 || (grid[i][j]>1 && grid[i][j]<time))
//         {
//           // THE LAST OR (||) CONDITION WE APPLY SO THAT WE DON'T REACH THAT NODE AGAIN 
//             return ;
//         }
        
//      // dfs call for all four directions if we find a fresh orange
      
        
//       grid[i][j]=time;
        
//       dfs(grid,i,j-1,rows,cols,time+1);
    
//       dfs(grid,i,j+1,rows,cols,time+1);
    
//       dfs(grid,i+1,j,rows,cols,time+1);
    
//       dfs(grid,i-1,j,rows,cols,time+1);
    
//     return ;
// }       

         
        vector<int> dr={1,0,-1,0};
        vector<int> dc={0,1,0,-1};
        
        int tm;
    void bfs(vector<vector<int>>&grid,queue<pair<pair<int,int>,int>>&q,vector<vector<int>>&visited,int n,
    int m,int &tm)
    {
        while(!q.empty())
        {
            
        // go to all four adjacent neightbours
                
            auto top=q.front();
                
            int row=top.first.first;
        
            int col=top.first.second;
            
            int time=top.second;
            
            q.pop();
            
            tm=time;
            
            for(int i=0;i<4;i++)
            {
                int nrow=row+dr[i];
                
                int ncol=col+dc[i];
                
if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && visited[nrow][ncol]==0 && (grid[nrow][ncol]==1) && grid[nrow][ncol]!=2)
                {
                    // increase time by one
                    q.push({{nrow,ncol},time+1});
                    
                    grid[nrow][ncol]=2; // now orange becomes rotten
                    
                    visited[nrow][ncol]=1;
                    
                    // mark as visited;
                    
                }
                else{
                    continue;
                }
                
            }
        }
    }
    
    int orangesRotting(vector<vector<int>>& grid)
    {
        // int rows=grid.size();
        
        // int time=2;
        // int cols=grid[0].size();
        
        // for(int i=0;i<grid.size();i++)
        // {
        //     for(int j=0;j<cols;j++)
        //     {
        //         if(grid[i][j]==2)
        //         {
        //             // 2 represent rotten orange
                    
        //             dfs(grid,i,j,rows,cols,time);
        //         }
                
        //     }
        // }

        
        // for(auto i:grid)
        // {
        //     for(auto j:i)
        //     {
        //         if(j==1)
        //         {
        //             // it means we find a fresh orange so return -1
        //             return -1;
        //         }
        //         // else{
        //             time=max(time,j);
        //         // }
                
        //     }
            
        // }
        // return time-2;
        
        
        //  using bfs 
        
        // make a pair of (i->row,j->col index) and time.
        
        queue<pair<pair<int,int>,int>>q;
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2 && visited[i][j]==0)
                {
                    q.push({{i,j},0});
                    
                    visited[i][j]=1;
                    
                    
                    // mark them as visited;
                    
                    // put all the rotten oranges into q
                }
            }
        }
        
        // call for bfs
        
        // THROUGH BFS WE STOP TO VISITED THAT NODE IF THAT NODE IS ALREADY VISTIED.
        
        tm=0;
        bfs(grid,q,visited,n,m,tm);
        
         for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && visited[i][j]!=1) return -1;
            }
        }
       return tm;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends