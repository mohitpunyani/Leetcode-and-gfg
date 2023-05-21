//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool dfs(int node,vector<int> adj[],unordered_map<int,bool>&visited,unordered_map<int,bool>&dfs_visited)
    {
        visited[node]=true;
        
        dfs_visited[node]=true;
        
        for(auto neighbours:adj[node])
        {
            if(!visited[neighbours])
            {
                bool ans=dfs(neighbours,adj,visited,dfs_visited);
                if(ans==true)
                {
                    return true;
                }
            }
                else if(dfs_visited[neighbours]==true)
                {
                    return true;
                    
                }
        }
        dfs_visited[node]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here

        // dfs
         
        // loop through handle disconnected components
        
        unordered_map<int,bool>visited;
        
        unordered_map<int,bool>dfs_visited;
        
        for(int i=0;i<V;i++){
            // if(!visited[i])
            // {
                bool ans=dfs(i,adj,visited,dfs_visited);
                if(ans==true){
                    return true;
                }
            // }
            
        }
       return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends