//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) 
    {
        // Code here
        
        // IT'S A VERY EASY ALGORITHM AND SIMILAR TO DIJKSTRA ALGORITUHM
        
        // V is the vertices or no of nodes
        
        int nodes=V;
        
        vector<int>distance(nodes,1e8);
        
        distance[S]=0;
        
        // AS WE KNOW THAT WE CAN'T APPLY BELLMAN FORD ON NEGATIVE CYCLE 
        
        for(int i=0;i<nodes-1;i++)
        {
            for(auto it:edges){
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                if(distance[u]!=1e8 && distance[u]+wt<distance[v])
                {
                    distance[v]=distance[u]+wt;
                }
            }
            
        }
        
        // to detect negative cycle
        
        bool negative_cycle=false;
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            
            if(distance[u]+wt<distance[v])
            {
                negative_cycle=true;
                break;
            }
        }
        if(negative_cycle==true){
            return {-1};
        }
        return distance;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
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

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends