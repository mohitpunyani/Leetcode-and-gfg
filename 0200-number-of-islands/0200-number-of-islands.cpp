class Solution {
public: 
    void solve(int i,int j,vector<vector<char>>&grid)
    {
        if(i<0 or j<0 or i==grid.size() or j==grid[0].size() or  grid[i][j]=='0')
        {
            return ;
        }

        // going to all four directions
        grid[i][j]='0';
        solve(i,j-1,grid); // left
        solve(i,j+1,grid); // right
        solve(i-1,j,grid);  // up
        solve(i+1,j,grid); // down
        return;
    }
    int numIslands(vector<vector<char>>& grid) 
    {
            int row=grid.size();
            int col=grid[0].size();
            int islands=0;
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<col;j++)
                {
                    if(grid[i][j]=='1')
                    {
                        islands++;
                        solve(i,j,grid);
                    }

                }

            }
            return islands;
    }
};