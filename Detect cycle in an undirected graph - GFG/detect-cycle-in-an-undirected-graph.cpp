//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
  
    // make a map of child and parent.
    
    // bool bfs(int node,vector<int>adj[],unordered_map<int,int>&parent,queue<int>&q,
    // unordered_map<int,bool>&visited)
    // {
    //     q.push(node);
        
    //     visited[node]=true;
        
    //     parent[node]=-1;
        
    //     while(!q.empty()){
            
    //         int node=q.front();
    //         q.pop();
            
    //         for(auto neighbours:adj[node])
    //         {
    //             if(!visited[neighbours]){
    //                 q.push(neighbours);
    //                 visited[neighbours]=true;
    //                 parent[neighbours]=node;
    //             }
    //             else if(visited[neighbours]==true && neighbours==parent[node]){
    //                 continue;
    //             }
    //             else if(visited[neighbours]==true && neighbours!=parent[node])
    //             {
    //                 return true;
    //             }
                
    //         }
    //     }
    //     return false;
        
    // }
    bool dfs(int node,int p,vector<int>adj[],unordered_map<int,bool>&visited,unordered_map<int,int>&parent)
    {
        // developed from bfs
        
        parent[node]=p;
        
        visited[node]=true;
        
        
        for(auto neighbours:adj[node])
        {
            if(!visited[neighbours])
            {
                bool cycle=dfs(neighbours,node,adj,visited,parent);
                if(cycle==true){
                    return true;
                }
                
            }
            else if(visited[neighbours]==true && neighbours==parent[node])
            {
                continue;
                
            }
            else if(visited[neighbours]==true && neighbours!=parent[node]){
                return true;
            }
            
        }
        return false;
        
    }
    bool isCycle(int V, vector<int> adj[])
    {
        //  Code here
         
        // using bfs
        
        // to handle for disconnected graph, we have to loop through this graph
        
        unordered_map<int,bool>visited;
        unordered_map<int,int>parent;
        // queue<int>q;
        // for(int i=0;i<V;i++){
        //     if(!visited[i])
        //     {
        //         bool ans=bfs(i,adj,parent,q,visited);
        //         if(ans==1){
        //             return true;
        //         }
        //     }
        // }
        // return false;
        
        // using dfs
        
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                bool ans=dfs(i,-1,adj,visited,parent);
                if(ans==1)
                {
                    return true;
                }
            }
            
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends