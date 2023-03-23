//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string>ans;
    string temp="";
    void solve(int i,int j,int row,int col,vector<vector<int>>&m,int n)
    {
        if(i>=row || j>=col  || i<0 || j<0 || m[i][j]==0)
        {
            return ;
        }
        if(i==row-1 && j==col-1)
        {
            // we reach the destination
            ans.push_back(temp);
            return ;
        }
        m[i][j]=0; // this indicates that the given index is visited
        // we make four calls
        
        // down
        temp.push_back('D');
        solve(i+1,j,row,col,m,n);
        temp.pop_back();
        
        
        // right
        temp.push_back('R');
        solve(i,j+1,row,col,m,n);
        temp.pop_back();
        
        
        // left
        temp.push_back('L');
        solve(i,j-1,row,col,m,n);
        temp.pop_back();
        
        
        // up
        temp.push_back('U');
        solve(i-1,j,row,col,m,n);
        temp.pop_back();
        
        // backtrack
        m[i][j]=1;
        return ;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        // we have four choices for each index
        
        int row=m.size();
        int col=m[0].size();
        solve(0,0,row,col,m,n);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends