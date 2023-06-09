//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    
    
    bool dfs(int node,int currVisited,vector<int>&visited,vector<int>adj [],int N){
        
        visited[node]=1;
        
        if(N==currVisited)
        {
            return true;
        }
        for(auto it:adj[node]){
            if(!visited[it])
            {
                bool ans=dfs(it,currVisited+1,visited,adj,N);
                if(ans==true)
                {
                    return true;
                }
                else{
                    continue;
                }
            }
        }
        visited[node]=0;
        return false;
    }
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        // code here
        
        // start to end visit karna hai 
        
        // dfs 
        
        vector<int>adj[N+1];
        
        vector<int>visited(N+1,0);
        
        // making a adjacency list
        
        for(auto e:Edges)
        {
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=1;i<=N;i++)
        {
            if(!visited[i]){
                bool ans=dfs(i,1,visited,adj,N);
                if(ans==true)
                {
                    return true;
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
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends