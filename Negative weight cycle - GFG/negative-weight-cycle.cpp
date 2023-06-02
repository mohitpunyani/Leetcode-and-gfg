//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges)
	{
	    
	    // Code here
	            
        int nodes=n;
        
        vector<int>distance(nodes,1e8);
        
        distance[0]=0;
        
        // AS WE KNOW THAT WE CAN'T APPLY BELLMAN FORD ON NEGATIVE CYCLE 
        
        for(int i=0;i<nodes-1;i++)
        {
            for(auto it:edges){
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                if(distance[u]!=1e8 && distance[u]+wt<distance[v])
                {
                    distance[v]=distance[u]+wt;
                }
            }
            
        }
        
        // to detect negative cycle
        
        bool negative_cycle=false;
    
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            
            if(distance[u]+wt<distance[v])
            {
                negative_cycle=true;
                break;
            }
        }
        if(negative_cycle==true){
            return 1;
        }
        return 0;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends