class Solution {
public:
void dfs(int s,int n,vector<bool>&visited,vector<vector<int>>&isConnected)
{
    visited[s]=true;
    // s=1
    // total nodes           1 2 3 4 5
// nodes connected to s(1)   1 1 0 1 0 // 3 and 5 are not connected to s

// so we only want to traverse the adjacent or neighbours of s but 3 and 
// 5 are not neighbours
vector<int>adj;
for(int i=0;i<n;i++)
{
    int x=isConnected[s][i];
    if(x==1){
        // means connected we find the neighbour
        adj.push_back(i);
    }
    
}
// traverse the adjacent
for(auto x:adj){
    if(!visited[x]){
        dfs(x,n,visited,isConnected);
    }
}
}
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int n=isConnected.size();
        int count=0;
        vector<bool>visited(n+1,false);
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                count++;
                dfs(i,n,visited,isConnected);
            }
        }
        return count;
    }
};