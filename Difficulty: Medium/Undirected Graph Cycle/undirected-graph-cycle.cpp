class Solution {
  public:
    
    bool dfs(int node,int p,vector<int> adj[],vector<bool>&visited,unordered_map<int,int>&parent)
    {
        visited[node]=true;
        parent[node]=p;
        for(auto &neighbours:adj[node])
        {
            if(!visited[neighbours])
            {
                bool ans=dfs(neighbours,node,adj,visited,parent);
                if(ans==true){
                    return true;
                }
                else{
                    continue;
                }
            }
             else if(visited[neighbours]==true && neighbours==parent[node])
            {
                continue;
                
            }
            else if(visited[neighbours]==true && neighbours!=parent[node]){
                return true;
            }
        }
        return false;
        
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        
        vector<int>adj [V];
        vector<bool>visited(V,false);
        unordered_map<int,int>parent;
        for(auto x:edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
            
        }
        for(int i=0;i<V;i++){
            if(!visited[i])
            {
                bool cycle=dfs(i,-1,adj,visited,parent);
                if(cycle){
                    return true;
                }
                else{
                    continue;
                }
            }
        }
        return false;
    }
};