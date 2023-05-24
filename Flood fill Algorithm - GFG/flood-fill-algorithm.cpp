//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

// void dfs(vector<vector<int>>&image,int i,int j,int newColor,int rows,int columns,int oldColor)
// {
//     if(i<0 || j<0 || i>=rows || j>=columns || image[i][j]!=oldColor)
//     {
//       return ; 
//     }
//     // dfs call for 4 directions
    
//     image[i][j]=newColor; 
    
//     dfs(image,i,j-1,newColor,rows,columns,oldColor);
    
//     dfs(image,i,j+1,newColor,rows,columns,oldColor);
    
//     dfs(image,i+1,j,newColor,rows,columns,oldColor);
    
//     dfs(image,i-1,j,newColor,rows,columns,oldColor);
    
//     return ;
// }


  int x[4]={-1,0,1,0};
  int y[4]={0,-1,0,1};
            
void efficient_dfs(vector<vector<int>>&visited,vector<vector<int>>&image,int i,int j,int oldColor,int newColor,int rows,int columns)
{
    visited[i][j]=1;
    // int x[]={-1,0,1,0};
//   int y[]={0,-1,0,1};
      
    image[i][j]=newColor;
    
    for(int k=0;k<4;k++)
    {
        int x1=i+x[k];
        int y1=j+y[k];
        
        if(x1>=0 && x1<rows && y1>=0 && y1<columns && visited[x1][y1]==0 && image[x1][y1]==oldColor)
        {
            
            efficient_dfs(visited,image,x1,y1,oldColor,newColor,rows,columns);
        }
        else{
            continue;
        }
    }
    return ;
    
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        // Code here 
        
        // similar to no. of islands
        
        // using dfs
        
        // base case
        
        
        int rows=image.size();
        
        int columns=image[0].size();
        
        int oldColor=image[sr][sc];
        if(oldColor==newColor){
            return image;
        }
        
        // dfs(image,sr,sc,newColor,rows,columns,oldColor);
        // return image;
        
        // efficient dfs approach 
        
        // due to visited array we stop the UNNECESSARY RECURSIVE CALLS
        
        
        vector<vector<int>>visited(rows,vector<int>(columns,0));
        efficient_dfs(visited,image,sr,sc,oldColor,newColor,rows,columns);
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends