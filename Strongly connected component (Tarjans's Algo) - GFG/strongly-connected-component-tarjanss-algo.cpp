//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
    public:
    
    vector<vector<int>>ans;
    
    int timer=1;
    
    stack<int>st;
    
    unordered_map<int,bool>recSt;
    
    void dfs(int node,unordered_map<int,bool>&visited,unordered_map<int,int>&parent,
    
    vector<int>&time_of_insertion,vector<int>&low,vector<int>adj [])
    {
        visited[node]=true;
        
        time_of_insertion[node]=timer;
        
        low[node]=timer;
        
        recSt[node]=true;
        
        st.push(node);
        
        timer++;
        
        for(auto neighbours:adj[node])
        {
            
            if(!visited[neighbours] && neighbours!=parent[node])
            {
                parent[neighbours]=node;
                
                dfs(neighbours,visited,parent,time_of_insertion,low,adj);
                
                // if any adjacent has less low time then update in me (parent is saying to adjacents)
                
                low[node]=min(low[node],low[neighbours]);
                
            }
            
            // checking cross edge
            else if(recSt[neighbours]==true)
            {
                // it means not a part of scc , there are other ways to visit that node 
                
                low[node]=min(low[node],low[neighbours]);
            }
            
        }
        
        // agar visited bhi hai aur parent bhi hai
        
        vector<int>temp;
        
        if(low[node]==time_of_insertion[node])
        {
            
            // means current node is a root of SCC
            while(st.top()!=node)
            {
                int val=st.top();
                
                temp.push_back(st.top());
                
                st.pop();
                
                recSt[val]=false;
                
            }
            

            temp.push_back(st.top());
            
            sort(temp.begin(),temp.end());
            
            st.pop();
            
            recSt[node]=false;
            
            ans.push_back(temp);
        }
        
        return ;
        
        
        
    }
	    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
	    // Code here
	    
	    // PRINT THE EDGES WHICH MAKES THE BRIDGES
	    
// VISITED  PARENT   DFS_TIME_TO_INSERTION_OF_NODE    LOWEST TIME INSERTION OF ALL ADJACENT NODES APART FROM PARENT



 // SIMILAR TO THE QUESTION THAT IS  PAIR OF NODES OR EDGE THAT MAKE A BRIDGE.
        
        
        // SIMILAR TO THE BRIDGE QUESTION OR CRITICAL CONNECTIONS
        
        
    int nodes=V;
    
    unordered_map<int,bool>visited;
    
    unordered_map<int,int>parent;
    

    vector<int>time_of_insertion(nodes);
    
    vector<int>low(nodes);
    
    for(int i=0;i<nodes;i++){
        visited[i]=false;
        parent[i]=-1;
    }
    
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
             dfs(i,visited,parent,time_of_insertion,low,adj);
        }
    }
    
    sort(ans.begin(),ans.end());
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

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}


// } Driver Code Ends