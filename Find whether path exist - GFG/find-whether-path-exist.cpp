//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    
    vector<int>dx={-1,0,1,0};
    vector<int>dy={0,1,0,-1};
    
    
    bool bfs(int x,int y,int rows,int cols,vector<vector<int>>&grid,vector<vector<int>>&visited,int target_X,int target_Y){
        
        queue<pair<int,int>>q;
        
        q.push({x,y});
        
        visited[x][y]=1;
        
        while(!q.empty())
        {
            auto top=q.front();
            
            int x_value=top.first;
            
            int y_value=top.second;
        
            q.pop();
            
            if(x_value==target_X && y_value==target_Y){
                return true;
            }

            
            for(int k=0;k<4;k++){
                
                int nrow=x_value+dx[k];
                
                int ncol=y_value+dy[k];
                
                if(nrow>=0 && ncol>=0 && nrow<rows && ncol<cols && visited[nrow][ncol]!=1 && grid[nrow][ncol]!=0)
                {
                    
                    q.push({nrow,ncol});
                    
                    visited[nrow][ncol]=1;
                }
                else{
                    continue;
                }
            }
            
        }
        return false;
    }
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        
        // DIJKSTRA ALGORITHM 
        
        // USING BFS 
        
        // USING PRIORITY_QUEUE OR QUEUEU AND VISITED ARRAY
        
        int src_x;
        int src_y;
        
        int dest_x;
        int dest_y;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)
                {
                    src_x=i;
                    src_y=j;
                    
                }
                else if(grid[i][j]==2){
                    dest_x=i;
                    dest_y=j;
                }
              
            }
        }
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        return bfs(src_x,src_y,n,m,grid,visited,dest_x,dest_y);
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends