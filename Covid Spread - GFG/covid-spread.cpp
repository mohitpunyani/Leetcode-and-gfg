//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution {
public:

    vector<int>dr = {-1,1,0,0};
    vector<int>dc= {0,0,-1,1};
         
    int ans=0;
    void bfs(vector<vector<int>>&hospital,queue<pair<int,pair<int,int>>>&q,vector<vector<int>>&visited)
    {
        
        while(!q.empty())
        {
            auto top=q.front();
            
            int time=top.first;
            
            int row=top.second.first;
            
            int col=top.second.second;
            
            ans=time;
            
            q.pop();
            
            for(int k=0;k<4;k++){
                int nrow=row+dr[k];
                int ncol=col+dc[k];
                
                if(nrow>=0 && ncol>=0 && nrow<hospital.size() && ncol<hospital[0].size() && hospital[nrow][ncol]==1
                && !visited[nrow][ncol])
                {
                    q.push({time+1,{nrow,ncol}});
                    
                    hospital[nrow][ncol]=2; // mark as infected;
                    
                    visited[nrow][ncol]=1; // mark as visited;
                }
                    
                else{
                    continue;
                }
            }
        }
        return ;
    }
    int helpaterp(vector<vector<int>> hospital)
    {
        //code here
        
        // IT IS LIKE ROTTEN ORANGES
        
        // using bfs
        
        // using queue
        
        queue<pair<int,pair<int,int>>>q;
        
        vector<vector<int>>visited(hospital.size(),vector<int>(hospital[0].size(),0));
        for(int i=0;i<hospital.size();i++){
            
            for(int j=0;j<hospital[0].size();j++)
            {
                if(hospital[i][j]==2 && !visited[i][j]){
                    
                    q.push({0,{i,j}});
                    
                    visited[i][j]=1;
                }
                else if(hospital[i][j]==0 && !visited[i][j])
                {
                    visited[i][j]=1;
                }
            }
        }
        bfs(hospital,q,visited);
        for(int i=0;i<hospital.size();i++){
            for(int j=0;j<hospital[0].size();j++){
                if(visited[i][j]!=1){
                    return -1;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends