//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    
    void dfs(int i,int j,vector<vector<int>>&grid,int &ans)
    {
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]==0)
        {
            return ;
        }
        
        // dfs call in 8 directions
        
        ans++;
        grid[i][j]=0;
        
        dfs(i + 1, j, grid, ans);
        dfs(i - 1, j, grid, ans);
        dfs(i, j + 1, grid, ans);
        dfs(i, j - 1, grid, ans);
        
        dfs(i + 1, j - 1, grid, ans);
        dfs(i + 1, j + 1, grid, ans);
        dfs(i - 1, j - 1, grid, ans);
        dfs(i - 1, j + 1, grid, ans);
        
        return ;

    }
    
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) 
    {
        // Code here
        
        int maxi=0;
        
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)
                {
                   dfs(i,j,grid,ans);
                   maxi=max(maxi,ans); 
                   ans=0;
                }
            }
        }
        return maxi;
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
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends