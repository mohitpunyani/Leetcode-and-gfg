//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  vector<int>dr={-1,0,+1,0};
   vector<int>dc={0,+1,0,-1};
    
    int MinimumEffort(vector<vector<int>>& heights)
    {
        // Code here
        
        // easy bfs
        
        // DIJKSTRA ALGORITHM USING PRIORITY QUEUE AND DISTANCE VECTOR
        
        // effort -> max of all difference in the path
        
        int n=heights.size();
        
        int m=heights[0].size();
        
    
        //  typedef pair<int, int> pi;
         typedef pair<int,pair<int,int>>pi;
         priority_queue<pi, vector<pi>, greater<pi> > pq;
         
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        
        pq.push({0,{0,0}});
        
        dist[0][0]=0;
    
        while(!pq.empty())
        {
            auto top=pq.top();
            
            int dis=top.first;
            
            int row=top.second.first;
            
            int col=top.second.second;
            
            pq.pop();
            
            
            for(int i=0;i<4;i++)
            {
                int nrow=row+dr[i];
                
                int ncol=col+dc[i];
                
                if(nrow>=0  && ncol>=0 && nrow<n && ncol<m )
                {
                    int diff=max(abs(heights[nrow][ncol]-heights[row][col]),dis);
                    if(diff<dist[nrow][ncol])
                    {
                        pq.push({diff,{nrow,ncol}});
                        dist[nrow][ncol]=diff;
                    }
                    else{
                        continue;
                    }
                }
                
                
            }

        }
        return dist[n-1][m-1];
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends