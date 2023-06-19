class Solution
{
    public:
    int recursive(int n)
    {
        if(n==0 or n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        int ans=0;
        // observe carefully
        
        for(int i=1;i<=n;i++)
        {
            
            ans=ans+recursive(i-1)*recursive(n-i); // catalan formula
            
            // i-1 is the call for left and n-i is the call for right
            
        }
        return ans;
        
    }
    
    // topdowndp
    
    int topdowndp(vector<int>&dp,int n)
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
            
            ans=ans+topdowndp(dp,i-1)*topdowndp(dp,n-i); // catalan formula
            
            // i-1 is the call for left and n-i is the call for right
            
        }
        dp[n]=ans;
        return dp[n];
    }
    
    int bottomupdp(int n)
    {
        vector<int>dp(n+1,0);
        
        dp[0]=1;
        dp[1]=1;
        // dp[2]=2;
        
        for(int i=2;i<=n;i++)
        {
            // i is the root node
            for(int j=1;j<=i;j++)
            {
                // j is the no .of nodes
                dp[i]=dp[i]+dp[j-1]*dp[i-j];
            }
        }
        
        return dp[n];
    }
    
        int numTrees(int n)
        {
            // return recursive(n);
        
            // vector<int>dp(n+1,-1);
            
            // return topdowndp(dp,n);
            
            
            return bottomupdp(n);
        }
};