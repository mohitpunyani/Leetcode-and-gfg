class Solution {
public:
    
    int recur(int n)
    {
        if(n==0)
        {
            return 0;
        }
        
        if(n==1){
            return 1;
        }
        
        int mx=INT_MAX;
        
        for(int i=1;i<=sqrt(n);i++)
        {
            
            int ans=recur(n-i*i);
            mx=min(mx,1+ans);

        }
        
        return mx;
    }
    
    int topdowndp(int n,vector<int>&dp)
    {
        
        if(n==0)
        {
            return 0;
        }
        
        if(n==1){
            return 1;
        }
        
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        int mx=INT_MAX;
        
        for(int i=1;i<=sqrt(n);i++)
        {
            
            int ans=topdowndp(n-i*i,dp);
            mx=min(mx,1+ans);

        }
        dp[n]=mx;
        
        return dp[n];
        
        
        
    }
    int numSquares(int n) 
    {
        
        // recursive
        
        // return recur(n);
        
        vector<int>dp(n+1,-1);
        
        return topdowndp(n,dp);
        
    }
};