//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++



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
    int minimumConnections(vector<vector<int>>& c,int n)
    {
        
        // IT'S A VERY EASY QUESTION , IT IS BASICALLY A QUESTION OF NO OF DISCONNECTED 
        // COMPONENTS IN A GRAPH
        
        // using bfs
        
        // MAKE A ADJACENCY LIST OF UNDIRECTED GRAPH
        
        vector<int>adj[n];
        
        if(c.size()<n-1)
        {
            // if edges is less than nodes than return -1 
            
            // you can't do connections
            
            return -1;
        }
        for(auto x:c)
        {
            int u=a[0];
            int v=a[1];
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

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int m;
        cin>>m;
        vector<vector<int>> c(m,vector<int> (2));
        for(auto &j:c)
            cin>>j[0]>>j[1];
        Solution s;
        cout<<s.minimumConnections(c,n)<<endl;
    }
    return 0;
}
// } Driver Code Ends