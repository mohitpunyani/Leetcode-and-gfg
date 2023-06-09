//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

   bool solve(int i,int j,vector<vector<char>>&board,string &word,int len){
       
       if(len==word.size()){
           return true;
       }
       if(i<0 or j<0 or i>=board.size() or j>=board[0].size() or board[i][j]!=word[len]){
           return false;
       }
       
       char ch=board[i][j];
       
       board[i][j]='#';
       
       bool opt1=solve(i-1,j,board,word,len+1);
       
       bool opt2=solve(i+1,j,board,word,len+1);
       
       bool opt3=solve(i,j-1,board,word,len+1);
       
       bool opt4=solve(i,j+1,board,word,len+1);
       
       // backtrack
       board[i][j]=ch;
       
       return opt1 || opt2 || opt3 || opt4 ;
       
   }
    bool isWordExist(vector<vector<char>>& board, string word) 
    {
        // Code here
        
        // using dfs
        
        // FIRST READ QUESTION VERY CAREFULLY THEN THINK
        
        int len=0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    bool ans=solve(i,j,board,word,0);
                    if(ans==true){
                        return true;
                    }
                }
                else{
                    continue;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends