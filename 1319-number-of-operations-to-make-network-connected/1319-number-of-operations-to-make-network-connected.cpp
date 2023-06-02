class Solution {
public:
    void bfs(int node,vector<int>adj [],vector<bool>&visited)
    {
        queue<int>q;
        
        q.push(node);
        
        visited[node]=true;
        
        while(!q.empty())
        {
            int top=q.front();
            
            q.pop();
            
            for(auto neighbours:adj[top]){
                if(!visited[neighbours])
                {
                    visited[neighbours]=true;
                    q.push(neighbours);
                }
            }
            
        }
        return ;
    }
    int makeConnected(int n, vector<vector<int>>& connections)
    {
        
        // IT'S A VERY EASY QUESTION , IT IS BASICALLY A QUESTION OF NO OF DISCONNECTED 
        // COMPONENTS IN A GRAPH
        
        // using bfs
        
        // MAKE A ADJACENCY LIST OF UNDIRECTED GRAPH
        
        vector<int>adj[n];
        
        if(connections.size()<n-1){
            return -1;
        }
        for(auto c:connections)
        {
            int u=c[0];
            int v=c[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
        int count=0;
        
        vector<bool>visited(n,false);
        
        for(int i=0;i<n;i++){
            if(!visited[i])
            {
                bfs(i,adj,visited);
                count++;
                
            }
        }
        if(count==0){
            return -1;
        }
        return count-1;
    }
};