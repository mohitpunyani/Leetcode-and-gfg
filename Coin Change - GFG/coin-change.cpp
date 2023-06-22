//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  // THIS CAN ALSO SOLVED USING INCLUSION EXCLUSION PRINCIPLE
  
  long long recursive(int coins[],int N,int sum,int idx)
  {
      if(sum==0){
          return 1;
      }
      if(sum<0){
          return 0;
      }
      long long int ans=0;
      for(int i=idx;i<N;i++)
      {
          ans=ans+recursive(coins,N,sum-coins[i],i);
      }
      return ans;
  }
   long long topdowndp(int coins[],int N,int sum,int index,vector<vector<long long>>&dp)
  {
      if(sum==0){
          return 1;
      }
      if(sum<0){
          return 0;
      }
      if(dp[index][sum]!=-1)
      {
          return dp[index][sum];
      }
      long long int ans=0;
      for(int i=index;i<N;i++)
      {
          ans=ans+topdowndp(coins,N,sum-coins[i],i,dp);
      }
      dp[index][sum]=ans;
      return dp[index][sum];
  }
  
  long long bottomupdp(int coins[],int N,int sum)
  {
      vector<vector<long long>>dp(N+1,vector<long long>(sum+1,0));
      for(int i=0;i<N;i++)
      {
          dp[i][0]=1;
      }
      for(int index=N-1;index>=0;index--)
      {
          for(int target=1;target<=sum;target++)
          {
              long long ans=0;
              if(target-coins[index]>=0)
              {
                  ans=ans+dp[index][target-coins[index]];
                  dp[index][target]=ans+dp[index+1][target];
              }
              
          }
      }
      return dp[0][sum];
      
  }
   long long space_optimization(int coins[],int N,int sum)
  {
      vector<long long>curr(sum+1,0);
      
      vector<long long>next(sum+1,0);
      
      for(int i=0;i<N;i++)
      {
          curr[0]=1;
      }
      for(int index=N-1;index>=0;index--)
      {
          for(int target=1;target<=sum;target++)
          {
              long long ans=0;
              if(target-coins[index]>=0)
              {
                  ans=ans+curr[target-coins[index]];
                  curr[target]=ans+next[target];
              }
              
          }
          next=curr;
      }
      return next[sum];
      
  }
   
   

    long long int count(int coins[], int N, int sum)
    {

        // code here.
        
        // return recursive(coins,N,sum,0);
        
        // vector<vector<long long>>dp(N,vector<long long>(sum+1,-1));
        // return topdowndp(coins,N,sum,0,dp);
        
        // return bottomupdp(coins,N,sum);
        
        return space_optimization(coins,N,sum);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends