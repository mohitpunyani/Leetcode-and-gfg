//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    
    
    bool is_safe_to_color(bool graph[101][101],int node,vector<int>&color,int n,int col)
    {
        // CHECK FOR THE ADJACENT NODES 
        for(int k=0;k<n;k++)
        {
            if(graph[k][node]==1 && color[k]==col)
            {
                // it means we can't colored
                
                return false;
            }
            
        }
        return true;
    }
    bool solve(bool graph[101][101],int m,int n,int node,vector<int>&color)
    {
        // we have m choices for each color
        
        if(node==n){
            return true;
        }
        for(int col=1;col<=m;col++)
        {
            if(is_safe_to_color(graph,node,color,n,col))
            {
                color[node]=col;
                
                // now apply dfs
                bool ans=solve(graph,m,n,node+1,color);
                if(ans==true)
                {
                    // COLOR SET BAITH GAYA SO WE DID NOT GO FOR MORE COLORS
                    return true;
                }
                color[node]=0; // backtrack (IMP).
                // IT MEANS KI WOH COLOR SET NAHI BAITHA WE HAVE TO TRY FOR DIFFERENT COLOR
            }
            
        }
        
        // SAARE COLOR TRY KAR LIYE BUT WE DID N'T GET THE ANSWER
        
        return false;
        
    }
    bool graphColoring(bool graph[101][101], int m, int n) 
    
    {
        // your code here
        
        // THIS QUESTION CAN BE OF DFS TRAVERSAL OR BACKTRACKING
        
        // NOTE OR CATCH -> WE HAVE M CHOICES FOR EACH NODE FOR COLORING
        
        vector<int>color(n,0); // important 
        
        //  draw recursive tree that will give you a better understanding.
        
        return solve(graph,m,n,0,color);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends