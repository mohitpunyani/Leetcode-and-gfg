//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	stack<int>st;
	
	unordered_map<int,bool>visited;
	
	void dfs(int node,vector<int>adj[])
	{
	    
	    visited[node]=true;
	    
	    for(auto neighbours:adj[node])
	    {
	        if(!visited[neighbours])
	        {
	            dfs(neighbours,adj);
	        }
	       // else if(visited[neighbours]){
	       //     return ;
	       // }
	        
	    }
	    st.push(node);
	    return ;
	}


void bfs(int V,vector<int>adj [],queue<int>&q,vector<int>&ans,vector<int>&indegree)
{
     
	    for(int i=0; i<V; i++)
	    {
	        if(indegree[i] == 0)
	        {
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty())
	    {
	        int a = q.front();
	        q.pop();
	        ans.push_back(a);
	        
	        for(auto it: adj[a])
	        {
	            indegree[it]--;
	            if(indegree[it] == 0) 
	               q.push(it);
	        }
	    }
	    
}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    
	    // METHOD 1 -> TOPOLOGICAL SORT USING DFS 
	      
	   // THIS APPROACH IS VERY EASY
	    
	    vector<int>ans;
	    
	    for(int i=0;i<V;i++)
	    {
	        if(!visited[i]){
	            dfs(i,adj);
	        }
	    }
	    while(!st.empty())
	    {
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	    
	    
	    // METHOD 2 -> TOPOLOGICAL SORT USING BFS USING  (KHAN'S ALGORITHM)
	   
	   

	   //  vector<int> indegree(V);
	    
	   // for(int i=0; i<V; i++)
	   // {
	   //     for(auto it : adj[i])
	   //     {
	   //         indegree[it]++;
	   //     }
	   // }
	    
	   // vector<int> ans;
	    
	   // queue<int> q;
	
	   // bfs(V,adj,q,ans,indegree);
	   
	
	   // return ans;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends