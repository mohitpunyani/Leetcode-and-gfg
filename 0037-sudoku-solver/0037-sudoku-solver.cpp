class Solution {
public:

bool isvalid(vector<vector<char>>&board,int row,int col,char val){
    for(int i=0;i<9;i++)
    {
        if(board[row][i]==val)
        {
            return false;// check for row
        }
        if(board[i][col]==val){
            return false;
        }
        if(board[3*(row/3)+i/3][3*(col/3)+i%3] == val) // 3*3 grid
         {
                return false;
        }
    }
    // for 3*3 grid
    // for (int i = row; i < row + 3; i++)
    //  {
    //         for (int j = col; j < col + 3; j++) 
    //         {

    //             if (board[i][j] == val) 
    //                 return false;
    //         }
    // }
    return true;

}
bool solve(vector<vector<char>>&board)
{
    for(int row=0;row<9;row++)
    {
        for(int col=0;col<9;col++)
        {
            if(board[row][col]=='.')
            {
                // try all values
                for(char val='1';val<='9';val++)
                {
                    if(isvalid(board,row,col,val))
                    {
                        board[row][col]=val;
                        if(solve(board)==true)
                        {
                            return true;
                        }
                        // else{
                            board[row][col]='.'; // backtrack;
                        // }

                    }
                }
                return false; // try all character but none is valid so return back and backtrack
            }
        }
    }
    return true;
}
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        return ;
    }
};