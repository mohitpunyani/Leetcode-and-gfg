



class Solution {
    void criticalDFS(int node,int time,vector<int>&disc,vector<int>&low,vector<int>&parent,
                     vector<vector<int>>&adj,vector<vector<int>>&ans){
        
        disc[node] = low[node] = time++;
        
        for(auto child : adj[node]){
            //if node has not been visited before
		
            if(disc[child] == -1){
			
			   //update parent information for child node
                parent[child] = node;
				
                criticalDFS(child,time,disc,low,parent,adj,ans);
                
				//while backtracking, update low value of parent to check if there is a back-edge
                low[node] = min(low[node],low[child]);
                
				//check if the edge is a bridge and not a back-edge from child/sub-graph of child
                //to it's parent or any of it's ancestors
                if(low[child] > disc[node]){
                    ans.push_back({node,child});
                }
            }
			
			//check just for a single back-edge
            else if(child != parent[node]){
			    //check and update if the ancestor was discovered before the earliest connected node to our current node
                low[node] = min(low[node],disc[child]);
            }
        }
    }
    
    
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        vector<vector<int>>ans;
        vector<int>disc(n,-1);
        vector<int>low(n,-1);
        vector<int>parent(n,-1);
        
        //build undirected graph
        vector<vector<int>>adj(n);
        for(auto it : connections){
            adj[it[1]].push_back(it[0]);
            adj[it[0]].push_back(it[1]);
        }
        for(int i=0;i<n;i++){
            if(disc[i] == -1){
                criticalDFS(i,0,disc,low,parent,adj,ans);
            }
        }
        return ans;
    }
};