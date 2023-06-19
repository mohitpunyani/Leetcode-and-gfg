//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the total number of possible unique BST.
    
    long long int mod=1000000007;
    int recursive(int n)
    {
        if(n==0 or n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        long long int ans=0;
        // observe carefully
        
        for(int i=1;i<=n;i++)
        {
            
            ans=(ans+((recursive(i-1)%mod)*(recursive(n-i)%mod))%mod)%mod; // catalan formula
            
            // i-1 is the call for left and n-i is the call for right
            
        }
        return ans;
        
    }
    
    // topdowndp
    
    int topdowndp(vector<long long int>&dp,int n)
    {
    if(n==0 or n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans=0;
        
        for(int i=1;i<=n;i++)
        {
            
            ans=(ans+((topdowndp(dp,i-1)%mod)*(topdowndp(dp,n-i)%mod))%mod)%mod; // catalan formula
            
            // i-1 is the call for left and n-i is the call for right
            
        }
        dp[n]=ans;
        return dp[n];
    }
    
    int bottomupdp(int n)
    {
        vector<long long int>dp(n+1,0);
        
        if(n==1)
        {
            return 1;
        }
        dp[0]=1; // for zero node
        dp[1]=1;  // for one node
        dp[2]=2;  // for two node
        
        
        for(int i=3;i<=n;i++)
        {
            // i is the no of nodes
            for(int j=1;j<=i;j++)
            {
                // j is the no of root nodes
                 dp[i]=(dp[i]+((dp[j-1]%mod)*(dp[i-j]%mod))%mod)%mod; 
                 //catalan numbers f4=f0f3+f1f2+f2f1+f3f0;
            }
        }
        
        return dp[n]%mod;
    }
    int numTrees(int N) 
    {
        // Your code here
        
        
           int n=N;
            // return recursive(n);
        
            // vector<long long int>dp(n+1,-1);
            
            // return (int)topdowndp(dp,n);
            
             
            return (int)bottomupdp(n);
        
    }
};

//{ Driver Code Starts.
#define mod (int)(1e9+7)
int main(){
    
    //taking total testcases
    int t;
    cin>>t;
    while(t--){
        
        //taking total number of elements
        int n;
        cin>>n;
        Solution ob;
        //calling function numTrees()
        cout<<ob.numTrees(n)<<"\n";
    }
}	
// } Driver Code Ends