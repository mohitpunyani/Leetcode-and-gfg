//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
    public:
   
   // SIMILAR TO TARJAN ALGORITHM OR BRIDGE IN A GRAPH ONLY LITTLE BIT CHANGE
    
    void dfs(int node, int parent, vector<int> &tin, vector<int> &low, vector<int> &vis,
             vector<int> adj[], int &timer, vector<int> &isArticulation){
                 vis[node] = 1;
                 tin[node] = low[node] = timer++;
                 int child = 0;
                 for(auto it: adj[node]){
                     if(!vis[it]){
                         dfs(it, node, tin, low, vis, adj, timer, isArticulation);
                         low[node] = min(low[it], low[node]);
                         if(low[it] >= tin[node] && parent != -1)
                            isArticulation[node] = 1;
                        child++;
                     }
                     else if(vis[it]==true && parent!=it)
                        low[node] = min(low[node], tin[it]);
                 }
                 
                 if(parent == -1 && child > 1)
                    isArticulation[node] = 1;
             }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int> tin(V, -1);
        vector<int> low(V, -1);
        vector<int> vis(V, 0);
        vector<int> isArticulation(V, 0);
        
        int timer = 1;
        for(int i = 0; i < V; i++){
            if(!vis[i])
                dfs(i, -1, tin, low, vis, adj, timer, isArticulation);
        }
        vector<int> ans;
        for(int i = 0; i < V; i++){
            if(isArticulation[i])
                ans.push_back(i);
        }
        if(ans.size() == 0) ans.push_back(-1);
        return ans;
    
	    
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
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends