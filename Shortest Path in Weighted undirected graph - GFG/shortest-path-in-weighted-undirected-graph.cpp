//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) 
    {
        // Code here
        
        // DISKSTRA ALGORITHM
        
        // very easy question using priority queue
        
        // using min heap
        
        typedef pair<int,int>pi;
        
        // making a adjacency list of undirected graph of n+1 nodes
        
        vector<int>dist(n+1,1e9);
        
        
        vector<int>parent(n+1,1);
        
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
        }
        vector<pair<int,int>>adj [n+1];
        
        for(auto e:edges)
        {
            int u=e[0];
            int v=e[1];
            int wt=e[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
            
        }
        
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        
        pq.push({0,1}); // distance and node
        
        dist[1]=0;
        
        while(!pq.empty()){
            auto top=pq.top();
            
            int d=top.first;
            
            int node=top.second;
            
            pq.pop();
            
            for(auto neighbours:adj[node])
            {
                int wt=neighbours.second;
                
                int v=neighbours.first;
                
                if(d+wt<dist[v])
                {
                    dist[v]=d+wt;
                    
                    parent[v]=node;
                
                    pq.push({dist[v],v});
                
                }
                
                else{
                    continue;
                }
            }
        }
        if(dist[n]==1e9){
            return {-1};
        }
        
        vector<int>path;
        while(parent[n]!=n){
            path.push_back(n);
            n=parent[n];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        return path;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends