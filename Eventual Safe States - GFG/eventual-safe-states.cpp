//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  
  bool dfs(unordered_map<int,bool>&visited,unordered_map<int,bool>&dfs_visited,int node,vector<int> adj [])
  {
      visited[node]=true;
      
      dfs_visited[node]=true;
      
      for(auto neighbours:adj[node]){
          if(!visited[neighbours]){
              bool ans=dfs(visited,dfs_visited,neighbours,adj);
              if(ans==true)
              {
                  return true;
              }
          }
          else if(visited[neighbours]==true && dfs_visited[neighbours]==true){
              return true;
          }
      }
      dfs_visited[node]=0;
      return false;
  }
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        // code here
        
        //  IF YOU FIND THE CYCLE YOU BREAK OUT 
        
        // using dfs 
        
        unordered_map<int,bool>visited;
        
        unordered_map<int,bool>dfs_visited;
        
        vector<int>ans;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bool ans=dfs(visited,dfs_visited,i,adj);
                if(ans==true)
                {
                    
                    continue;
                }
            }
        }
        for(int i=0;i<V;i++){
            if(dfs_visited[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends