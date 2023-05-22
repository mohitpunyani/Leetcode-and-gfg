//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
 
  
  vector<int>bfs(unordered_map<int,list<int>>&adj,unordered_map<int,bool>&visit , int node , int dist,int N){
      queue<int>q;
      
      q.push(node);
      
      vector<int>ans(N,-1);
      
      unordered_map<int,int>parent;
      
       parent[node] = dist;
       visit[node] = true;
      while(!q.empty()){
          int front = q.front();
          q.pop();
       
          for(auto child: adj[front]){
              if(!visit[child]){
                  q.push(child);
                  visit[child] = true;
                                    
                  parent[child] = parent[front]+1;
              }
          }
      }
      
      for(int i =0 ; i<N; i++){
          if(parent.find(i)!=parent.end()){
          ans[i] = parent[i];
          }
      }
      return ans;
  }
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src)
    {
        // code here
        
        // METHOD 1 -> USING BFS
        
        // FIRST PREPARE A ADJACENCY LIST 
        
      
    unordered_map<int,list<int>>adj;
     for(int i =0 ; i<M;i++){
         int u = edges[i][0];
         int v = edges[i][1];
         adj[u].push_back(v);
         adj[v].push_back(u);
     }
     unordered_map<int,bool>visit;
     return bfs(adj,visit,src,0,N);
    
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends