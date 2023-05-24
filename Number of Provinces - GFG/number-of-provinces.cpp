//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
  void bfs(int node,unordered_map<int,bool>&visited,queue<int>&q,vector<int> adjlist[],int V)
  {
      q.push(node);
      visited[node]=true;
      
      while(!q.empty())
      {
          int top=q.front();
          
          q.pop();
          
          for(auto neighbours:adjlist[top])
          {
              if(!visited[neighbours]){
                  q.push(neighbours);
                  visited[neighbours]=true;
              }
              else{
                  continue;
              }
              
          }
    
          
      }
      return ;
      
  }
    int numProvinces(vector<vector<int>> adj, int V)
    {
        // code here
        
        //  using bfs algorithm
        
        // here vertices or nodes represent the cities
       
       // make a adjacency liST THROUGH VECTOR
       
       // NOTE -> basically we have to find total no. of disconnected groups
       
       
       vector<int> adjlist[V+1];
       
       for(int i=0;i<V;i++)
       {
           for(int j=0;j<V;j++)
           {
               if(adj[i][j]==1)
               {
                   // i+1 and j+1 are the indexes or nodes which represent the cities
                   
                   adjlist[i+1].push_back(j+1);
                   
                //   adjlist[j+1].push_back(i+1);
                
                
                   
               }
               
           }
       }
       
       // bfs
       
       unordered_map<int,bool>visited;
      
       queue<int>q;
        
       int count=0;
       
       for(int i=1;i<=V;i++)
       {
           if(!visited[i])
           {
               
               count++;
               bfs(i,visited,q,adjlist,V);
               
           }
       }
       return count;
       
       // we can also solve this question using dfs and disjoint set
       
       
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends