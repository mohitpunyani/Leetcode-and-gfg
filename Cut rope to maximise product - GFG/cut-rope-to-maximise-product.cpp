//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
     
    
    long long recursive(int n)
    {
        if(n==1){
            return 1;
        }
        if(n==2){
            return 1;
        }
        
        long long  ans=0;
        for(long long i=1;i<n;i++)
        {
            long long temp=recursive(n-i);
            long long  prod=i*max(n-i,temp);
            ans=max(ans,prod);
        }
        
        return ans;
        
    } 
    
    long long topdowndp(int n,vector<long long>&dp)
    {
        if(n==1){
            return 0;
        }
        if(n==2){
            return 1;
        }
        
        if(dp[n]!=-1){
            return dp[n];
        }
        long long  ans=0;
        
        for(long long i=1;i<n;i++)
        {
            long long temp=topdowndp(n-i,dp);
            long long  prod=i*max(n-i,temp);
            ans=max(ans,prod);
        }
        dp[n]=ans;
        return ans;
        
    }
    
    long long maxProduct(int n)
    {
        // code here
        
        // we have choices 
        
        // recursion 
        
        // return recursive(n);
        
        vector<long long>dp(n+1,-1);
        return topdowndp(n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.maxProduct(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends