//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K) 
    
    {
        // Code here
        
        // make a directed graph using adjacency list
        
        // dijkstra algorithm
        
        vector<pair<int,int>>adj[n];
        
        for(auto it:flights)
        {
            int city1=it[0];
            int city2=it[1];
            int prize=it[2];
            adj[city1].push_back({city2,prize});
            
        }
        
        vector<int>distance(n,1e9);
        
        distance[src]=0;
        
       
        queue<pair<int,int>>pq;
        
         
        // {cost,node}
        
        pq.push({0,src});
        
        int stops=0;
        while(!pq.empty())
        {
            
            int size=pq.size();
            
        while(size--)
        {
            auto top=pq.front();
            
            int node=top.second;
            
            int prize=top.first;
            
            pq.pop();
            
            if(stops>K)
            {
                break;
            }
            for(auto it:adj[node])
            {
                int adjNode=it.first;
                
                int adjCost=it.second;
                
                if(prize+adjCost < distance[adjNode])
                {
                    distance[adjNode]=prize+adjCost;
                    pq.push({distance[adjNode],adjNode});
                    
                }
                else{
                    continue;
                }
                
            }
        }
            stops++;
        }
        if(distance[dst]==1e9){
            return -1;
        }
        return distance[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends