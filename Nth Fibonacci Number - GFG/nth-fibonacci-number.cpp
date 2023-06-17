//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
  // RECURSIVE
   int mod=1000000007;

   long long int recursive(long long int n)
   {
       
       // base case
       if(n==0){
           return 0;
       }
       if(n==1 or n==2){
           return 1;
       }
       
       // recursive calls
       long long int ans=recursive(n-1)+recursive(n-2);
       return ans;
   }
   
   long long int topdowndp(vector<int>&dp,long long int n){
       
       if(n==0){
           return 0;
       }
       if(n==1 or n==2){
           return 1;
       }
       if(dp[n]!=-1){
           return dp[n];
       }
       dp[n]=(topdowndp(dp,n-1)+topdowndp(dp,n-2))%mod;
       return dp[n]%mod;
   }
   
   long long int bottomupdp(long long int n)
   {
       vector<int>dp(n+1,0);
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        
        for(int i=3;i<=n;i++)
        {
            dp[i]=(dp[i-1]+dp[i-2])%mod;
        }
        return dp[n];
       
   }
   
   long long int space_optimization(long long int n){
       
       long long int prev1=1;
       long long int prev2=1;
       
       for(int i=3;i<=n;i++)
       {
           long long int curr=(prev1+prev2)%mod;
           
           prev1=prev2;
           
           prev2=curr;
           
       }
      return prev2;
   }
    long long int nthFibonacci(long long int n)
    {
        // code here
        // return recursive(n);
        
        
        // TOP DOWN dp
        
        // vector<int>dp(n+1,-1); // contains both 0 and 1 based indexing
        // long long int ans=topdowndp(dp,n);
        // return ans;
        
        // BOTTOM UP DP 
        
        // return bottomupdp(n);
        
        //  SPACE OPTIMIZATION  (play with variables)
        
        return space_optimization(n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends