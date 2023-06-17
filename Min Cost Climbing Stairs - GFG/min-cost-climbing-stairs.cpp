//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
  int recursive(vector<int>&cost,int N)
  {
      // base case
      if(N==0){
          return cost[0];
      }
     if(N==1)
     {
          return cost[1];
     }
     int ans=cost[N]+min(recursive(cost,N-1),recursive(cost,N-2));
     return ans;
    
  }
  
  int topdowndp(vector<int>&cost,vector<int>&dp,int N){
      
    if(N==0){
        return cost[0];
      }
     if(N==1)
     {
          return cost[1];
     }
     if(dp[N]!=-1){
         return dp[N];
     }
     dp[N]=cost[N]+min(topdowndp(cost,dp,N-1),topdowndp(cost,dp,N-2));
     return dp[N];
  }
  
  int bottomupdp(vector<int>&cost,int N)
  {
      
      vector<int>dp(N+1,0);
      
      
      dp[0]=cost[0];
      
      dp[1]=cost[1];
      
      for(int i=2;i<=N;i++){
          
          // starting for array of size 3
          
          dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
          
      }
      return min(dp[N-1],dp[N-2]);
  }
    int minCostClimbingStairs(vector<int>&cost ,int N) 
    {
        //Write your code here
        
        // recursive
        // return recursive(cost,N);
        
        // TOPDOWNDP
        
        // vector<int>dp(N+1,-1);
        // return min(topdowndp(cost,dp,N-1),topdowndp(cost,dp,N-2));
        
        // BOTTOMUP DP
        
        return bottomupdp(cost,N);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>cost(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>cost[i];
        }

        Solution ob;
        cout<<ob.minCostClimbingStairs(cost,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends