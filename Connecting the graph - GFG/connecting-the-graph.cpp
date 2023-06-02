//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++



class DisjointSet
{
    public:


    // make array of size n+1 , it handles both 1 based and 0 based indexing

    vector<int>parent;
    vector<int>rank;
    
    // make a constructor for initialization

    DisjointSet(int n)
    {
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            rank[i]=0;
        }
    }

    int findparent(int node)
    {
        if(node==parent[node]){
            return node;
        }
        parent[node]=findparent(parent[node]);
        return parent[node];

    }
    void union_by_rank(int u,int v)
    {
        int ultimate_parent_u=findparent(u);
        int ultimate_parent_v=findparent(v);;
        if( ultimate_parent_u==ultimate_parent_v)
        {
            // that means both are belong for same component
            return ;
        }
        else{
            if(rank[ultimate_parent_u]==rank[ultimate_parent_v])
            {
                parent[ultimate_parent_v] =ultimate_parent_u;
                rank[ultimate_parent_u]++;
            }
            else if(rank[ultimate_parent_u]>rank[ultimate_parent_v]){
                // connect smaller rank to the larger rank
                parent[ultimate_parent_v]=ultimate_parent_u;

            }
            else if(rank[ultimate_parent_u]<rank[ultimate_parent_v])
            {
                parent[ultimate_parent_u]=ultimate_parent_v;

            }
        }


    }
};
class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        
        DisjointSet ds(n);
        
        if(edge.size()<n-1){
            return -1;
        }
        for( auto it  :  edge)
        {
            int  u = it[0];
             
            int v = it[1];

            if(ds.findparent(u) == ds.findparent(v))
            {
                continue;
             
            }
            else{

             ds.union_by_rank(u , v);

            }

        }
     int compo =0 ;

        for(int i = 0 ; i < n ; i++){

          if(ds.parent[i] == i){

              compo++;
          }  
        }
        return compo-1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends