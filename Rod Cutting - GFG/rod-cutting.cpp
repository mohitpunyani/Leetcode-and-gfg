//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
//   NOTE -> BASED ON INCLUSION EXCLUSION PRINCIPLE

//  DO CALCULATIONS VERY CAREFULLY 
// unbounded knapsack

  int recursive(int price[],int rod_length,int n,int index)
  {
      
      if(rod_length<=0)
      {
          return 0;
      }
      if(index>n){
          return 0;
      }
      int pick=INT_MIN;
      if(rod_length>=index){
          pick=price[index]+recursive(price,rod_length-index,n,index);
      }
      int not_pick=0+recursive(price,rod_length,n,index+1);
      int ans=max(pick,not_pick);
      return ans;
  }
  
  int topdowndp(int price[],int rod_length,int n,int index,vector<vector<int>>&dp)
  {
      
      if(rod_length<=0)
      {
          return 0;
      }
      if(index>n){
          return 0;
      }
      if(dp[index][rod_length]!=-1){
          return dp[index][rod_length];
      }
      int pick=INT_MIN;
      if(rod_length>=index){
          pick=price[index-1]+topdowndp(price,rod_length-index,n,index,dp);
      }
      int not_pick=0+topdowndp(price,rod_length,n,index+1,dp);
      int ans=max(pick,not_pick);
      dp[index][rod_length]=ans;
      return dp[index][rod_length];
      
  }
  
  int bottomupdp(int price[],int n){
      
      int length=n;
      vector<vector<int>>dp(n+2,vector<int>(length+1,0));
      
      for(int i=0;i<=n;i++)
      {
          dp[i][0]=0;
          
      }
      for(int i=n;i>=0;i--){
          for(int length=1;length<=n;length++)
          {
              int pick=INT_MIN;
              if(length>=i)
              {
                  pick=price[i-1]+dp[i][length-i];
                  
              }
              int not_pick=dp[i+1][length];
              dp[i][length]=max(pick,not_pick);
          }
          
      }
      return dp[0][n];
     
  }
    int cutRod(int price[], int n)
    {
        //code here
        
        int length=n;
        // return recursive(price,length,n,1);
        
        // vector<vector<int>>dp(n+1,vector<int>(length+1,-1));
        // return topdowndp(price,length,n,1,dp);
        
        return bottomupdp(price,n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends