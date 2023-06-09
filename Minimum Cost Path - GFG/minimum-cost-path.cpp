//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    
    typedef pair<int,pair<int,int>>pi;
    
    int ans;
    
    vector<int>dx = {-1 , 1 , 0 , 0};
    
    vector<int>dy = {0 , 0 , -1, 1};
 
    void bfs(int i,int j,vector<vector<int>>&visited,vector<vector<int>>&grid,int n,int m)
    {
        visited[i][j]=1;
        
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        
        pq.push({grid[i][j],{i,j}});
        
        while(!pq.empty()){
            
            auto top=pq.top();
            
            int dist=top.first;
            
            int row=top.second.first;
            
            int col=top.second.second;
            
            ans=dist;
            
            pq.pop();
            
            if(row==n-1 && col==m-1){
                return ;
            }
            
            for(int k=0;k<4;k++)
            {
                int nrow=row+dx[k];
                
                int ncol=col+dy[k];
                
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !visited[nrow][ncol])
                {
                    pq.push({dist+grid[nrow][ncol],{nrow,ncol}});
                    
                    visited[nrow][ncol]=1;
                }
                
            }
            
        }
        return ;
        
    }
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        
        // using dijkstra algorithm  (priority queue and visited array)
        
        // bfs
        
        
        int n=grid.size();
        
        int m=grid[0].size();
        
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        bfs(0,0,visited,grid,n,m);
        
        return ans;
        
        
        
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
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends