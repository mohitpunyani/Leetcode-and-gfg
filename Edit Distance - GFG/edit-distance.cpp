//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  int solve(string s,string t,int i,int j)
  {
      if(i==s.size())
      {
          return t.size()-j;
      }
      if(j==t.size())
      {
          return s.size()-i;
      }
      
      int ans=INT_MAX;
      if(s[i]==t[j])
      {
          return solve(s,t,i+1,j+1);
      }
      else{
          
          // we have three choices 
          int insert_ans=1+solve(s,t,i,j+1);
          int remove_ans=1+solve(s,t,i+1,j);
          int replace_ans=1+solve(s,t,i+1,j+1);
          int temp=min({insert_ans,remove_ans,replace_ans});
          ans=min(ans,temp);
      }
      return ans;
  }  
  
  int topdowndp(string s,string t,int i,int j,vector<vector<int>>&dp)
  {
      if(i==s.size())
      {
          return t.size()-j;
      }
      if(j==t.size())
      {
          return s.size()-i;
      }
      
      if(dp[i][j]!=-1){
          return dp[i][j];
      }
      int ans=INT_MAX;
      if(s[i]==t[j])
      {
          return topdowndp(s,t,i+1,j+1,dp);
      }
      else{
          
          // we have three choices 
          int insert_ans=1+topdowndp(s,t,i,j+1,dp);
          int remove_ans=1+topdowndp(s,t,i+1,j,dp);
          int replace_ans=1+topdowndp(s,t,i+1,j+1,dp);
          int temp=min({insert_ans,remove_ans,replace_ans});
          ans=min(ans,temp);
          
      }
      dp[i][j]=ans;
      return dp[i][j];
  }
  
  int bottomupdp(string s,string t)
  {
      int n=s.size();
      int m=t.size();
      
      vector<vector<int>>dp(n+1,vector<int>(m+1,0));
      
  }
    int editDistance(string s, string t)
    {
        // Code here
        
        // easy question (now your thinking is developed)
        
        // recursive 
        // return solve(s,t,0,0);
        
        // topdowndp
        
        vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,-1));
        
        return topdowndp(s,t,0,0,dp);
        
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends