//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        // PRIM'S ALGORITHM (STRIVER)
        
        typedef pair<int,int>pi;
        
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        
        // make a min heap of weight and node
        
        
        
        unordered_map<int,bool>visited;;
        
        pq.push({0,0});
        
        int sum=0;
        
        
        while(!pq.empty())
        {
            int weight=pq.top().first;
            
            int node=pq.top().second;
            
            pq.pop();
            
            
            if(!visited[node])
            {
                sum+=weight;
                visited[node]=true;
                
                for(auto it:adj[node])
                {
                    
                    int node=it[0];
                    
                    int weight=it[1];
                    
                    if(visited[node]==false)
                    {
                        pq.push({weight,node});
                    }
                    else{
                        continue;
                    }
                    
                    
                }
                
            }
            
            
        }
        return sum;
        
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends