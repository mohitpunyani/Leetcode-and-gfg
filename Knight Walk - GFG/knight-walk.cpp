//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

 
    int min_steps=0;
    
    vector<int>dr={1,-1,-2,-2,-1,1,2,2};
    vector<int>dc={-2,-2,-1,1,2,2,1,-1};
    
    int bfs(vector<int>&KnightPos,vector<int>&TargetPos,int N,vector<vector<bool>>&visited)
    {
        // make a queue with pair of xy and steps
        queue<pair<pair<int,int>,int>>q;
        
        q.push({{KnightPos[0],KnightPos[1]},0});
        
        visited[KnightPos[0]][KnightPos[1]]=true;
        
        while(!q.empty())
        {
            auto top=q.front();
            
            q.pop();
            
            int row=top.first.first;
            
            int col=top.first.second;
            
            int steps=top.second;
            
            min_steps=steps;
            
            if(row==TargetPos[0] && col==TargetPos[1]){
                return min_steps;
            }
            for(int i=0;i<8;i++)
            {
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(nrow>=0 && ncol>=0 && nrow<=N && ncol<=N && visited[nrow][ncol]==false)
                {
                    q.push({{nrow,ncol},steps+1});
                    visited[nrow][ncol]=true;
                    
                }
                else{
                    continue;
                }
            }
            
        }
        return -1;
        
    }
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N)
	{
	    // Code here
	     
	    // NOTE -> WHERE YOU FIND MINIMUM THINK ABOUT BFS
	    
	    // IN A CHESS KNIGHT  SO WE CAN MOVES IN 8 DIRECTIONS
	    
	    // it's a one based indexing so make N+1 size vector
	    
	    vector<vector<bool>>visited(N+1,vector<bool>(N+1,false));
	    
	    return bfs(KnightPos,TargetPos,N,visited);
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends