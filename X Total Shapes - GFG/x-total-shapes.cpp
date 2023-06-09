//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    
    void dfs(int i,int j,vector<vector<char>>&grid){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]=='O')
        {
            return ;
            
        }
        
        grid[i][j]='O';
        dfs(i,j-1,grid);
        dfs(i,j+1,grid);
        dfs(i-1,j,grid);
        dfs(i+1,j,grid);
        return ;
    }
    //Function to find the number of 'X' total shapes.
    int xShape(vector<vector<char>>& grid) 
    {
        // Code here
        
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='X'){
                    
                dfs(i,j,grid);
                ans++;
                }
                
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends