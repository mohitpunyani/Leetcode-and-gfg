class Solution {
  public:
    
    int sum=0;
    int bfs(vector<vector<int>>edges [],vector<bool>&visited)
    {
        typedef pair<int,int>pi;
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        pq.push({0,0});
        while(!pq.empty())
        {
            int wt=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(visited[node]==true)
            {
                continue;
            }
            sum=sum+wt;
            visited[node]=true;
            for(auto &neighbours:edges[node])
            {
                int v=neighbours[0];
                int w=neighbours[1];
                if(!visited[v])
                {
                    pq.push({w,v});
                }
                else{
                    continue;
                }
                    
            }
        }
        return sum;
    }
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        // int n=adj.size();

        vector<bool>visited(V,false);
        return bfs(adj,visited);
    
        
    }
};