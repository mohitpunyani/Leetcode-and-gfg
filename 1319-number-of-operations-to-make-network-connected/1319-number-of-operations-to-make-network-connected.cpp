class Solution {
public:
     int find(int x, vector<int>& parent) {
 		if (parent[x] == x) return parent[x];
        return parent[x] = find(parent[x], parent);
 	}
//     void bfs(int node,vector<int>adj [],vector<bool>&visited)
//     {
//         queue<int>q;
        
//         q.push(node);
        
//         visited[node]=true;
        
//         while(!q.empty())
//         {
//             int top=q.front();
            
//             q.pop();
            
//             for(auto neighbours:adj[top]){
//                 if(!visited[neighbours])
//                 {
//                     visited[neighbours]=true;
//                     q.push(neighbours);
//                 }
//             }
            
//         }
//         return ;
//     }
    int makeConnected(int n, vector<vector<int>>& connections)
    {
        
        // IT'S A VERY EASY QUESTION , IT IS BASICALLY A QUESTION OF NO OF DISCONNECTED 
        // COMPONENTS IN A GRAPH
        
        // using bfs
        
        // MAKE A ADJACENCY LIST OF UNDIRECTED GRAPH
        
//         vector<int>adj[n];
        
//         if(connections.size()<n-1)
//         {
//             // if edges is less than nodes-1 than return -1 
            
//             // you can't do connections
            
//             return -1;
//         }
//         for(auto c:connections)
//         {
//             int u=c[0];
//             int v=c[1];
//             adj[u].push_back(v);
//             adj[v].push_back(u);
            
//         }
//         int count=0;
        
//         vector<bool>visited(n,false);
        
//         for(int i=0;i<n;i++){
//             if(!visited[i])
//             {
//                 bfs(i,adj,visited);
//                 count++;
                
//             }
//         }
//         if(count==0){
//             return -1;
//         }
//         return count-1;
        
        
        // 2ND APPROACH DISJOINT SET APPROACH 
        

    

        //Initializing parent array with their own parent values
        vector<int> parent(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
        
        //For counting components
 		int compo = 0;
        
        if(connections.size()<n-1){
            return -1;
        }
        for (auto& it: connections) {
 			int x = find(it[0], parent);
 			int y = find(it[1], parent);
 			
            //If parent are same that means they were connected and now again they are being connected so continue/skip
            if (x == y){
                continue;
            }
            
            //If Parent not same, then Union them and increment compo.
            else {
                parent[y] = x; //union
                // compo++;
            }
 		}
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (parent[i] == i)
                ans++;
        
        return ans-1;
        
        
        //We know to connect n computers we need n-1 cables so if connections.size() < n-1 return -1
		//else required - already connected and i.e. (n-1) - (components)
        // return connections.size() < n-1 ? -1 : n-1-compo;
    }
};