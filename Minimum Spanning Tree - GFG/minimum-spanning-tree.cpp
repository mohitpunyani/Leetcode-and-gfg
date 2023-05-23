//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// THIS IS FOR KRUSKAL ALGORITHM
class DisjointSet
{
    public:


    // make array of size n+1 , it handles both 1 based and 0 based indexing

    vector<int>parent;
    vector<int>rank;
    
    // make a constructor for initialization

    DisjointSet(int n)
    {
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=1;i<=n;i++){
            parent[i]=i;
            rank[i]=0;
        }
    }

    int findparent(int node)
    {
        if(node==parent[node]){
            return node;
        }
        parent[node]=findparent(parent[node]);
        return parent[node];

    }
    void union_by_rank(int u,int v)
    {
        int ultimate_parent_u=findparent(u);
        int ultimate_parent_v=findparent(v);;
        if( ultimate_parent_u==ultimate_parent_v)
        {
            // that means both are belong for same component
            return ;
        }
        else{
            if(rank[ultimate_parent_u]==rank[ultimate_parent_v])
            {
                parent[ultimate_parent_v] =ultimate_parent_u;
                rank[ultimate_parent_u]++;
            }
            else if(rank[ultimate_parent_u]>rank[ultimate_parent_v]){
                // connect smaller rank to the larger rank
                parent[ultimate_parent_v]=ultimate_parent_u;

            }
            else if(rank[ultimate_parent_u]<rank[ultimate_parent_v])
            {
                parent[ultimate_parent_u]=ultimate_parent_v;

            }
        }


    }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        // METHOD 1 -> PRIM'S ALGORITHM (STRIVER)
        
        
        // typedef pair<int,int>pi;
        
        // priority_queue<pi,vector<pi>,greater<pi>> pq;
        
        // // make a min heap of weight and node
        
        
        
        // unordered_map<int,bool>visited;;
        
        // pq.push({0,0});
        
        // int sum=0;
        
        // while(!pq.empty())
        // {
        //     int weight=pq.top().first;
            
        //     int node=pq.top().second;
            
        //     pq.pop();
            
            
        //     if(!visited[node])
        //     {
        //         sum+=weight;
        //         visited[node]=true;
                
        //         for(auto it:adj[node])
        //         {
                    
        //             int node=it[0];
                    
        //             int weight=it[1];
                    
        //             if(visited[node]==false)
        //             {
        //                 pq.push({weight,node});
        //             }
        //             else{
        //                 continue;
        //             }
                    
                    
        //         }
                
        //     }
            
            
        // }
        
        // return sum;
        
        
        // METHOD 2 -> KRUKSHAL ALGORITHM 
        
        // TWO CONCEPTS
        
        // 1. DISJOINT SET 
        
        //  two important operations performed by disjoint set
        
        //   a. find parent or find set
        
        //   b. union or union set
        
        // 2. UNION BY RANK AND PATH COMPRESSION 
        
        //  above two operation also performed by union by rank and path compression in a efficient manner.
        
        
        //  make a adjaency list 
        
        vector<pair<int,pair<int,int>>>edges;
        
        // we have to sort on the basis of weight.
        
        for(int i=0;i<V;i++)
        {
            for(auto x:adj[i])
            {
                int adjNode=x[0];
                int weight=x[1];
                int node=i;
                
                edges.push_back({weight,{node,adjNode}});
                
            }
            
        }
        
        DisjointSet ds(V);
        sort(edges.begin(),edges.end());
        
        int mstWt=0;
        for(auto it:edges)
        {
            
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
            
            if(ds.findparent(u)!=ds.findparent(v)){
                mstWt+=wt;
                ds.union_by_rank(u,v);
            }
        }
        
        return mstWt;
        
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