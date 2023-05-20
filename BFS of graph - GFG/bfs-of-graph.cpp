//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    

  public:
      
      queue<int>q;
      unordered_map<int,bool>visited;
      
      void bfs(int start, vector<int> &ans, vector<int> adj[])
      {
          
        q.push(start);
        visited[start] = true;
        while(!q.empty())
        {
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(auto it : adj[node]){
                if(!visited[it]){
                    q.push(it);
                    visited[it] = true;
                }
            }
        }
    }
    
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> ans;
        
        queue<int> q;
        

        bfs(0,ans,adj);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends