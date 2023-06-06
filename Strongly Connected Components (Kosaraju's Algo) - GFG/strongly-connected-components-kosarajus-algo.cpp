//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	unordered_map<int,bool>visited;
	
	stack<int>st;
	
	void topological_sort(int node,vector<vector<int>>&adj)
	{
	
	    visited[node]=true;
	    
	    for(auto it : adj[node])
	    {
	        if(!visited[it])
	        {
	            topological_sort(it,adj);
	        }
	        else{
	            continue;
	        }
	        
	    }
	    st.push(node);
	    return ;
	}
	
	void dfs(int node,vector<int>transpose[])
	{
	     visited[node]=true;
	    
	     for(auto it:transpose[node])
	     {
	         
	         if(!visited[it])
	         {
	             dfs(it,transpose);
	         }
	         else{
	             continue;
	         }
	     }
	    return ;
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        
        // THREE STEPS 
        
        // step 1 toplogical sort
        

        int nodes=V;
        for(int i=0;i<nodes;i++)
        {
            if(!visited[i]){
                
            topological_sort(i,adj);
            }
        }
        
        // step 2 transpose or reverse the graph
    
        
        // transpose the graph
        
        vector<int> transpose[nodes];
        for(int i=0;i<nodes;i++)
        {
            visited[i]=false;
            
            for(auto v:adj[i])
            {
                transpose[v].push_back(i);
                
            }
            
        }
        // step 3 do dfs on topological ordering
        
        int ans=0;
        while(!st.empty())
        {
            int val=st.top();
            st.pop();
            if(!visited[val])
            {
                ans++;
                dfs(val,transpose);
            }
        }
        return ans;
        
        
    
        
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends