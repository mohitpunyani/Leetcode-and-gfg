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
    
    int bottomupdp(int n){
        
        vector<int>dp(n+1,0);
        
        dp[0]=0;
        
        dp[1]=1;
        
        for(int i=2;i<=n;i++)
        {
            int mx=INT_MAX;
            
            for(int j=1;j<=sqrt(n);j++)
            {
                if(i-j*j>=0)
                {
                    int ans=dp[i-j*j];
                    mx=min(mx,1+ans);
                }
                
            }
            dp[i]=mx;
            
        }
        return dp[n];

    }
    
    int numSquares(int n) 
    {
        
        // recursive
        
        // return recur(n);
        
        // vector<int>dp(n+1,-1);
        
        // return topdowndp(n,dp);
        
        return bottomupdp(n);
        
    }
};