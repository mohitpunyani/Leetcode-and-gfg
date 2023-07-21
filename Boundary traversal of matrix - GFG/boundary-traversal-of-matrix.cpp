//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m) 
    {
        // code here
        
        
        int first_row=0;
        int last_row=n-1;
        int first_col=0;
        int last_col=m-1;
        
        vector<int>ans;
        
        for(int col=0;col<m;col++)
        {
            ans.push_back(matrix[first_row][col]);
        }
        for(int row=1;row<n;row++)
        {
            ans.push_back(matrix[row][last_col]);
        }
        if(first_row!=last_row){
            
            for(int col=m-2;col>=0;col--)
            {
                ans.push_back(matrix[last_row][col]);
            }
        }
        if(first_col!=last_col){
            
            for(int row=n-2;row>=1;row--)
            {
                ans.push_back(matrix[row][first_col]);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.boundaryTraversal(matrix, n, m);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends