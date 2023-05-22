//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        
        // method 1 using queue
        
        // vector<int>distance(V,INT_MAX);
        
        // distance[S]=0;
        
        // queue<int>q;
        
        // q.push(S);
        
        // while(!q.empty())
        // {
        //     int top=q.front();
            
        //     q.pop();
            
            
        //     for(auto it:adj[top])
        //     {
        //         int node=it[0];
                
        //         int weight=it[1];
                
        //         if(distance[node]>distance[top]+weight)
        //         {
        //             distance[node]=distance[top]+weight;
        //             q.push(node);
                
        //         }
        //         else if(distance[node]<=distance[top]+weight)
        //         {
        //             continue;
        //         }
        //     }
        // }
        
        // return distance;
        
        // METHOD 2 -> DIJKSTRA ALGORITHM USING PRIORITY QUEUE OR SET
        
        // using priority queue (this approach is developed from approach 1 )
        
        // MAKE A MINHEAP OF DISTANCE AND NODE
        
        // SORT TAKES PLACE ON THE BASIS OF FIRST VALUE OF PAIR (WHICH IS DISTANCE)
        
         typedef pair<int, int> pi;

         priority_queue<pi, vector<pi>, greater<pi> > pq;
         
         
         pq.push({0,S});
         

         vector<int>dis(V,INT_MAX);
         
         dis[S]=0;
         
         while(!pq.empty())
         {
             int top=pq.top().second;
             
             int distance=pq.top().first;
             
             pq.pop();
             
             for(auto it:adj[top])
             {
                 int node=it[0];
                 
                 int weight=it[1];
                 
                 if(dis[node] >  weight + distance)
                 {
                     dis[node]=weight+distance;
                     pq.push({dis[node],node});
                 }
                 else{
                     continue;
                 }
                 
             }
             
         }
        
    return dis;
        
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends