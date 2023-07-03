//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

public:

// A WORD SHOULD NOT INCLUDE MULTIPLE INSTANCES OF THE SAME CELL 
bool solve(int i,int j,vector<vector<bool>>&visited,vector<vector<char>>&board,vector<string>&dictionary,string temp,int n,int m)
{
    
    // recursive calls in all 8 directions
    
    if(temp.size()==0)
    {
        return true;
    }
    if(i>=n or j>=m or i<0 or j<0 or visited[i][j]==true or temp[0]!=board[i][j])
    {
        return false;
    }
    
    visited[i][j]=true;
    
    temp=temp.substr(1);
    
    bool ans1=solve(i-1,j,visited,board,dictionary,temp,n,m);
    bool ans2=solve(i+1,j,visited,board,dictionary,temp,n,m);
    bool ans3=solve(i,j-1,visited,board,dictionary,temp,n,m);
    bool ans4=solve(i,j+1,visited,board,dictionary,temp,n,m);
    bool ans5=solve(i-1,j-1,visited,board,dictionary,temp,n,m);
    bool ans6=solve(i-1,j+1,visited,board,dictionary,temp,n,m);
    bool ans7=solve(i+1,j+1,visited,board,dictionary,temp,n,m);
    bool ans8=solve(i+1,j-1,visited,board,dictionary,temp,n,m);
    
    visited[i][j]=false;
    
    // backtracking done , because board can have  different cells have same character     
    return ans1 or ans2 or ans3 or ans4 or ans5 or ans6 or ans7 or ans8;
}

//  THERE IS ALSO A ANOTHER WAY TO WRITE DFS

	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary)
	{
	    // Code here
	    
	    // it's a question of dfs
	    
	    int n=board.size();
	    
	    int m=board[0].size();
	    
	    set<string>s;
	    for(int i=0;i<dictionary.size();i++){
	        string temp=dictionary[i];
	        vector<vector<bool>>visited(n,vector<bool>(m,false));
	        for(int i=0;i<n;i++){
	            for(int j=0;j<m;j++)
	            {
	               // if(board[i][j]==temp[0])
	               // {
	                    if(solve(i,j,visited,board,dictionary,temp,n,m))
	                    {
	                        s.insert(temp);
	                        break;
	                        
	                   // }
	                }
	            }
	            
	
	        }
	    }
	    vector<string>v(s.begin(),s.end());
	    return v;
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends