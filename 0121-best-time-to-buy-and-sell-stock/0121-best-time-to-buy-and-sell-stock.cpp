class Solution {
public:
    
    int recursive(int i,int k,bool buy,vector<int>&prices,int n)
    {
        if(i>=n or k<=0){
            return 0;
        }
        
        int profit=0;
        
        if(buy==1)
        {
           // we have two choices buy karo yah ignore karo  
            int buykaro=-prices[i]+recursive(i+1,k,!buy,prices,n);
            int ignorekaro=recursive(i+1,k,buy,prices,n);
            profit=max(buykaro,ignorekaro);
            
        }
        else{
           // agar buy kar liya toh sell karo             
            
            int sellkaro=prices[i]+recursive(i+1,k-1,!buy,prices,n);
            int ignorekaro=recursive(i+1,k,buy,prices,n);
            profit=max(sellkaro,ignorekaro);
        }
        
        return profit;
        
    } 
    
    int topdowndp(int i,int k,bool buy,vector<int>&prices,int n,vector<vector<int>>&dp)
    {
        if(i>=n or k<=0){
            return 0;
        }
        
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        int profit=0;
        
        if(buy==1)
        {
           // we have two choices buy karo yah ignore karo  
            int buykaro=-prices[i]+topdowndp(i+1,k,!buy,prices,n,dp);
            int ignorekaro=topdowndp(i+1,k,buy,prices,n,dp);
            profit=max(buykaro,ignorekaro);
            
        }
        else{
           // agar buy kar liya toh sell karo             
            
            int sellkaro=prices[i]+topdowndp(i+1,k-1,!buy,prices,n,dp);
            int ignorekaro=topdowndp(i+1,k,buy,prices,n,dp);
            profit=max(sellkaro,ignorekaro);
        }
        
        dp[i][buy]=profit;
        return dp[i][buy];
        
    }
    
    // tabulation
int bottomupdp(int k,bool buy,vector<int>&prices,int n)
    {
        vector<vector<int>>dp(n+1,vector<int>(2,0));
    
        for(int i=n-1;i>=0;i--){
            for(int buy=1;buy>=0;buy--)
            {
                
                int profit=0;
                if(buy==1)
                {
                   // we have two choices buy karo yah ignore karo  
                    int buykaro=-prices[i]+dp[i+1][!buy];
                    int ignorekaro=dp[i+1][buy];
                    profit=max(buykaro,ignorekaro);

                }
                else{
                   // agar buy kar liya toh sell karo             

                    int sellkaro=prices[i]+dp[i+1][!buy];
                    int ignorekaro=dp[i+1][buy];
                    profit=max(sellkaro,ignorekaro);
                }
                dp[i][buy]=profit;
            }
        }
      return dp[0][0];
    }

    
    // OPTIMIZED APPROACH 
    
    int solve1(vector<int>&prices,int n)
    {
        int mx=0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int profit=prices[j]-prices[i];
                mx=max(mx,profit);
                
            }
        }
        return mx;
        
    }
    
    int solve2(vector<int>&prices,int n){
        
         vector<int>maxPrices(n);
        
        int element=INT_MIN;
        
         for(int i=n-1;i>=0;i--)
         {
             element=max(element,prices[i]);
             maxPrices[i]=element;
             
         }
         
        int max_profit=0;
        for(int i=0;i<n;i++)
        {
            int diff=maxPrices[i]-prices[i];
            max_profit=max(max_profit,diff);
        
        }
        return max_profit;
    }
    
    int solve3(vector<int>&prices,int n)
    {
        // using max and min concept
        int mx=INT_MAX;
        
        //  basically sabse minimum aur maximum ka difference nikalna hai
        
        int max_profit=0;
        for(int i=0;i<n-1;i++)
        {
            mx=min(mx,prices[i]);
            int diff=prices[i+1]-mx;
            max_profit=max(max_profit,diff);
        }
        return max_profit;
    }
    
    int maxProfit(vector<int>& prices)
    {
        // WE HAVE TO PLAY WITH A BOOLEAN VARIABLE THAT INDICATES BUY AND SELL
        
        // RECURSIVE
        
        // we can do atmost k transactions
        
        int n=prices.size();
        
        // return recursive(0,1,1,prices,n);
        
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        // return topdowndp(0,1,1,prices,n,dp);
        
        // return bottomupdp(1,1,prices,n); // this code is wrong
        
        // MAY BE TABULATION CAN BE SOLVED USING 3D MATRIX
        
        
        // MORE APPROACHES APART FROM DYNAMIC PROGRAMMING
        
        // return solve1(prices,n);
        
        // return solve2(prices,n);
        
        return solve3(prices,n);
    }
};