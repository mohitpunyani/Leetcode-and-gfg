//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    
    int mod=1000000007;
    int topdowndp(vector<int>&dp,int n)
    {
         if(n==0 or n==1)
        {
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n]=(topdowndp(dp,n-1)+topdowndp(dp,n-2))%mod;
        return dp[n];
    }
    
    int bottomupdp(int n)
    {
        vector<int>dp(n+1,0);
        
        dp[0]=1;
        dp[1]=1;
        
        for(int i=2;i<=n;i++){
            dp[i]=(dp[i-1]+dp[i-2])%mod;
        }
        return dp[n];
    }
    int recursive(int n){
        if(n==0 or n==1)
        {
            return 1;
        }
        int ans=recursive(n-1)+recursive(n-2);
        return ans;
    }
    int countWays(int n)
    {
        // your code here
        // return recursive(n);
        
        
        // TOPDOWN DP
        
        // vector<int>dp(n+1,-1);
        
        // return topdowndp(dp,n);
        
        // BOTTOMUP DP
        
        return bottomupdp(n);
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends