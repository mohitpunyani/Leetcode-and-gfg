//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

 bool bfs(vector<int>&color,vector<int>adj[],int V,int node)
 {
     queue<int>q;
     q.push(node);
     color[node]=0;
     while(!q.empty())
     
     {
         auto node=q.front();
         
         q.pop();
         
         for(auto neighbours:adj[node])
         {
             if(color[neighbours]==-1)
             {
                //  if the adjacent node is yet not colored
                
                // so i will give the opposite color of the node
                
                 color[neighbours]=!color[node];
                 q.push(neighbours);
                 
             }
             else if(color[neighbours]!=-1 && color[neighbours]==color[node])
             {
                 // if the adjacent node having same color 
                 
                 // someone did color it on some other path
                 
                 return false;
                 
             }
             
         }
         
     }
     return true;
     
 }
	bool isBipartite(int V, vector<int>adj[])
	{
	    // Code here
	    
	    // ------- STRIVER ----------
	    
	    // WE HAVE ONLY TWO COLORS
	    
	    // A GRAPH IS BIPARTITE SUCH THAT NO TWO ADJACENT NODES HAVE SAME COLOR
	    
	    // TWO CONCLUSIONS (VV.IMP)
	    
	    // 1.  LINEAR GRAPH IS ALWAYS BIPARTITE
	    
	    // 2.  A GRAPH WITH EVEN LENGTH OF CYCLE IS A BIPARTITE
	    
	    // A GRAPH WITH ODD LENGTH OF CYCLE IS NOT A BIPARTITE.
	    
	    // TAKE TWO COLORS 0 AND 1
	    
	    
	    vector<int>color(V,-1);
	    for(int i=0;i<V;i++)
	    {
	        if(color[i]==-1){
	            bool ans=bfs(color,adj,V,i);
	            if(ans==false){
	                return false;
	            }
	            
	        }
	    }
	    return true;
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends