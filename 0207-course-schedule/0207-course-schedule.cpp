class Solution {
public:
    bool solve(int node,vector<bool>&visited,vector<bool>&dfs_visited,vector<vector<int>>&adj)
    {
        visited[node]=true;
        dfs_visited[node]=true;

        for(auto &neighbours:adj[node])
        {
            if(!visited[neighbours])
            {
                bool ans=solve(neighbours,visited,dfs_visited,adj);
                if(ans==true){
                    return true;
                }
                else{
                    continue;
                }
            }
            else if(dfs_visited[neighbours]==true)
            {
                // cycle present
                return true;
                
            }
        }
        dfs_visited[node]=false;
        return false;

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        // cycle in directed graph 
        // DFS (VISITED AND DFS_VISITED ARRAY) , BFS(KHAN'S ALGO(DAG) or TOPOLOGICAL SORTING(DAG))

        int V=numCourses;
        vector<vector<int>>adj(V);
        for(int i=0;i<prerequisites.size();i++)
        {
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[u].push_back(v);
        }
        
        vector<bool>visited(V,false);
        vector<bool>dfs_visited(V,false);
        for(int i=0;i<V;i++)
        {
            if(!visited[i]){

                bool ans=solve(i,visited,dfs_visited,adj);
                if(ans==true)
                {
                    return false;
                }
                else{
                    continue;
                }
            }
        }
        return true;
    }
};