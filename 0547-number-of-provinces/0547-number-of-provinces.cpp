class Solution {
public:

    void solve(int node,unordered_map<int,list<int>>&mp,vector<bool>&visited)
    {
        visited[node]=true;
        for(auto &neighbours:mp[node])
        {
            if(!visited[neighbours])
            {
                solve(neighbours,mp,visited);
            }
            else{
                continue;
            }

        }
        return ;
    }

    int findCircleNum(vector<vector<int>>& isConnected)
    {
        
        // cycle detection in undirected graph

        unordered_map<int,list<int>>mp;
        int n=isConnected.size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    mp[i+1].push_back(j+1);
                    mp[j+1].push_back(i+1);
                }
                
            }
        }
        int counts=0;
        vector<bool>visited(n+1,false);
        for(int i=1;i<=n;i++)
        {
            if(!visited[i])
            {

                counts++;
                solve(i,mp,visited);
            }
        }
        return counts;
    }
};