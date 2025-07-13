// User Function Template
class Solution {
  public:
     void bfs(int src,vector<pair<int,int>> mp[],vector<int>&ans)
     {
             typedef pair<int,int>pi;
            priority_queue<pi,vector<pi>,greater<pi>>pq;
            pq.push({0,src}); // minimum weight 
            while(!pq.empty())
            {
              
                
                int d=pq.top().first; // d
                int node=pq.top().second; // node
                pq.pop();
                for(auto &neighbours:mp[node])
                {
                    int v=neighbours.first;
                    int wt=neighbours.second;
                    if(ans[v]>wt+ans[node])
                    {
                        ans[v]=wt+ans[node];
                        pq.push({ans[v],v});
                    }
                    else{
                        continue;
                     }
                }
            }
            return ;
     }
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        // unordered_map<int,list<pair<int,int>>>mp;
        vector<pair<int,int>>mp[V];
        
        int n=edges.size();
        // USED MIN HEAP TO GET MIN WEIGHT ON THE top
        
        for(int i=0;i<n;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            mp[u].push_back({v,wt});
            mp[v].push_back({u,wt});
            
        }
     
        vector<int>ans(V,INT_MAX);
        ans[src]=0;
        bfs(src,mp,ans);
        return ans;
    }
};