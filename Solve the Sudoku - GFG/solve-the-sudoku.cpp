//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends

class Solution 
{
    public:
        bool issafe(int val,int grid[N][N],int row,int col)
    {
        // check for row
        for(int i=0;i<N;i++)
        {
            // row check
            if(grid[row][i]==val)
            {
                return false;
            }
            
        }
        // column check
        for(int j=0;j<N;j++){
            if(grid[j][col]==val){
                return false;
            }
        }
        // in 3*3 submatrix
        for(int i=0;i<N;i++)
        {
             if(grid[3*(row/3)+i/3][3*(col/3)+i%3]==val)
             {
                 // learn this condition
                 
                return false;
             }
        }
        return true;
    }

    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        for(int row=0;row<9;row++)
        {
            for(int col=0;col<9;col++)
            {
                if(grid[row][col]==0)
                {
                    // it means we get an empty cell 
                    // toh ab 1 se lekar 9 tak saari values check kar ki konsi safe hai.
                    for(int val=1;val<=9;val++)
                    {
                        if(issafe(val,grid,row,col))
                        {
                            grid[row][col]=val;
                            
                            // ek case solve kar liya baaki recursion sambhal lega.
                            
                            // recursivecall
                            
                            bool ans=SolveSudoku(grid);
                            if(ans==true)
                            {
                                return true;
                            }
                        
                            else
                            {
                                grid[row][col]=0;
                            }
                        }
                    }
                    return false; 
                }
            }
        }
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0;i<N;i++)
        {
           for(int j=0;j<N;j++)
           {
               cout<<grid[i][j]<<" ";
           }
       }
        
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends