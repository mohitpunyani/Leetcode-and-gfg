class Solution {
public:
    
    stack<int>st;
bool  dfs(int node,vector<int>  adj [],unordered_map<int,bool>& visited,unordered_map<int,bool> &dfs_visited)
    
    {
        visited[node]=true;
    
        dfs_visited[node]=true;
    
        for(auto neighbours:adj[node]){
            if(!visited[neighbours])
            {
                bool ans=dfs(neighbours,adj,visited,dfs_visited);
                if(ans==true){
                    return true;
                }
                
            }
            else if(visited[neighbours]==true && dfs_visited[neighbours]==true)
            {
                return true;
            }
        }
        st.push(node);
    
        dfs_visited[node]=false;
    
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        
        // making adjacency list 
        
    
        vector<int>adj[numCourses];
        for(auto it:prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }
        unordered_map<int,bool>visited;
        
        unordered_map<int,bool>dfs_visited;
        
        vector<int>topo;
        
        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i])
            {
                bool ans=dfs(i,adj,visited,dfs_visited);
                if(ans==true)
                {
                    // means cycle is present so it means topological sort is not possible
                    return {};
                }
                else{
                    continue;
                }
                
            }
            
        }
        while(!st.empty()){
            topo.push_back(st.top());
            st.pop();
        }
        return topo;
    }
};