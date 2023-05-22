//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
  void prepare_adj_list(unordered_map<int,list<pair<int,int>>>&adjlist, vector<vector<int>>&edges,int M)
  {
      for(int i=0;i<M;i++)
      {
          int u=edges[i][0];
          int v=edges[i][1];
          int weight=edges[i][2];
          
          adjlist[u].push_back({v,weight});
          
      }
      
  }
  
  void topological_sort(int node,unordered_map<int,list<pair<int,int>>>&adjlist,unordered_map<int,bool>&visited,stack<int>&st)
  {
      
      visited[node]=true;
      
      for(auto it:adjlist[node])
      {
          int neighbour=it.first;
          if(!visited[neighbour])
          {
              topological_sort(neighbour,adjlist,visited,st);
              
          }
      }
      st.push(node);
      return ;
      
  }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges)
     {
        // code here
        
        // USING CONCEPT OF TOPLOGICAL SORT 
        
        // EASY QUESTION BUT WE HAVE TO OBSERVE CAREFULLY
        
        // we also have to store weight 
        
        unordered_map<int,list<pair<int,int>>>adjlist;
        
        prepare_adj_list(adjlist,edges,M);
        
        unordered_map<int,bool>visited;
        stack<int>st;
        
        topological_sort(0,adjlist,visited,st);
        
        
        vector<int>distance(N,1e9);
        
        
        distance[0]=0;
        while(!st.empty())
        {
            
            int top=st.top();
            
            st.pop();
            
            for(auto it:adjlist[top])
            {
                int node=it.first;
                
                int weight=it.second;
                
                if(distance[node]>weight+distance[top])
                {
                    distance[node]=weight+distance[top];
                    
                }
                else if(distance[node]<=distance[top]+weight)
                {
                    // distance[node]=distance[node];
                    continue;
                    
                }
                
                
            }
        }
            for(int i=0;i<N;i++){
                if(distance[i]==1e9){
                    distance[i]=-1;
                }
            }
    
        return distance;

       
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends