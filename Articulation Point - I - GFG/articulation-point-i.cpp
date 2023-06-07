//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
    public:
   
   // STRIVER  SERTIES
   
   // SIMILAR TO TARJAN ALGORITHM OR BRIDGE IN A GRAPH ONLY LITTLE BIT CHANGE
    
    int timer=1;
    
void dfs(int node, unordered_map<int,int>&parent, vector<int> &time_of_insertion, vector<int> &low, unordered_map<int,bool>&visited,
        vector<int> adj[],vector<int> &isArticulation)
            {
                 visited[node] = true;
                 
                 time_of_insertion[node] = low[node] = timer;
                 
                 timer++;
                 
                 
                 int child = 0;
                 
                 for(auto it: adj[node])
                 {
                     
                     if(!visited[it])
                     {
                         parent[it]=node;
                         
                         dfs(it, parent, time_of_insertion, low, visited, adj, isArticulation);
                         
                         low[node] = min(low[it], low[node]);
                         
                         child++;
                         
                         if(low[it] >= time_of_insertion[node] && parent[node]!= -1)
                         
                            isArticulation[node] = 1;
                            
                         else continue;
                     }
                     else if(visited[it]==true && parent[node]!=it)
                        low[node] = min(low[node], time_of_insertion[it]);
                 }
                 
        // IF THE SAME PARENT HAS MULTIPLE CHILDS THEN THAT IS DEFINATELY AN ARTICULATION POINT
                 
             if(parent[node] == -1 && child > 1){
                    isArticulation[node] = 1;
             }
             return ;
             }
             
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int> time_of_insertion(V, -1);
        
        vector<int> low(V, -1);
        
        unordered_map<int,bool>visited(V);
        
        unordered_map<int,int>parent(V);
        for(int i=0;i<V;i++){
            visited[i]=false;
            parent[i]=-1;
        }
        
        vector<int> isArticulation(V, 0);
        
        
        for(int i = 0; i < V; i++){
            if(!visited[i])
                dfs(i, parent, time_of_insertion, low, visited, adj, isArticulation);
        }
        vector<int> ans;
        for(int i = 0; i < V; i++){
            if(isArticulation[i]==1)
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