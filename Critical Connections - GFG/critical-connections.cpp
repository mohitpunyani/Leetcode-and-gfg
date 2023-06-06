//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

// IMPORTANT QUESTION


class Solution {
    public:
    
    vector<vector<int>>bridges;
    
    int timer=1;
    
    void dfs(int node,unordered_map<int,bool>&visited,unordered_map<int,int>&parent,
    
    vector<int>&time_of_insertion,vector<int>&low,vector<int>adj [])
    {
        visited[node]=true;
        
        time_of_insertion[node]=timer;
        
        low[node]=timer;
        
        timer++;
        
        for(auto neighbours:adj[node])
        {
            
            if(!visited[neighbours])
            {
                parent[neighbours]=node;
                
                dfs(neighbours,visited,parent,time_of_insertion,low,adj);
                
                // if any adjacent has less low time then update in me (parent is saying to adjacents)
                
                low[node]=min(low[node],low[neighbours]);
                
                // condition for having bridge
                
                if(time_of_insertion[node]<low[neighbours])
                {
                    if(neighbours>node){
                        bridges.push_back({node,neighbours});
                    }
                    else{
                        bridges.push_back({neighbours,node});
                    }
                    
                    
                }
                else{
                    continue;
                }
                
            }
            else if(visited[neighbours]==true && neighbours!=parent[node])
            {
                low[node]=min(low[node],low[neighbours]);
            }
            
        }
        
        // agar visited bhi hai aur parent bhi hai
        
        return ;
        
        
        
    }
	vector<vector<int>>criticalConnections(int V, vector<int> adj[])
	{
	    // Code here
	    
	    // PRINT THE EDGES WHICH MAKES THE BRIDGES
	    
// VISITED  PARENT   DFS_TIME_TO_INSERTION_OF_NODE    LOWEST TIME INSERTION OF ALL ADJACENT NODES APART FROM PARENT

    int nodes=V;
    
    unordered_map<int,bool>visited;
    
    unordered_map<int,int>parent;
    

    vector<int>time_of_insertion(nodes);
    
    vector<int>low(nodes);
    
    for(int i=0;i<nodes;i++){
        visited[i]=false;
        parent[i]=-1;
    }
    
    // for(int i=0;i<V;i++)
    // {
    //     if(!visited[i])
    //     {
            dfs(0,visited,parent,time_of_insertion,low,adj);
        // }
    // }
    sort(bridges.begin(),bridges.end());

   	 return bridges;
	    
	}
};

//{ Driver Code Starts.

int main(){
	int tc;
    cin >> tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}
// } Driver Code Ends