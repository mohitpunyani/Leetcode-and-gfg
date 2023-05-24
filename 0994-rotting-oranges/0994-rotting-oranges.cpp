class Solution {
public:
    
    // for understand this dfs you have to dry run 
    
    // NOTE -> WE USE TIME VARIABLE OR TIME +1 SO THAT WE DON'T REACH THAT NODE AGAIN AND       AGAIN 
    void dfs(vector<vector<int>>&grid,int i,int j,int rows,int cols,int time)
    {
        // IF WE FIND EMPTY CELL THAN WE HAVE TO RETURN 
        
if(i<0 || j<0 || i>=rows || j>=cols || grid[i][j]==0 || (grid[i][j]>1 && grid[i][j]<time))
        {
            return ;
        }
        
     // dfs call for all four directions if we find a fresh orange
        
        grid[i][j]=time;
        
     dfs(grid,i,j-1,rows,cols,time+1);
    
    dfs(grid,i,j+1,rows,cols,time+1);
    
    dfs(grid,i+1,j,rows,cols,time+1);
    
    dfs(grid,i-1,j,rows,cols,time+1);
    
    return ;
}       
        
    
    int orangesRotting(vector<vector<int>>& grid)
    {
        int rows=grid.size();
        
        int time=2;
        int cols=grid[0].size();
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j]==2)
                {
                    // 2 represent rotten orange
                    
                    dfs(grid,i,j,rows,cols,time);
                }
                
            }
        }

        
        for(auto i:grid)
        {
            for(auto j:i)
            {
                if(j==1)
                {
                    // it means we find a fresh orange so return -1
                    return -1;
                }
                // else{
                    time=max(time,j);
                // }
                
            }
            
        }
        return time-2;
        
    }
};