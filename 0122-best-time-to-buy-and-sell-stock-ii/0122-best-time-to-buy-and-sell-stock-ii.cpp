class Solution {
    private:
    int recursive(int index,int buy,vector<int> &prices,int n){
        if(index>=n){
            return 0;
        }
        int profit=0;
        if(buy==1){
            // two choice hai buy karo yah ignore karo
            int buykaro=-prices[index]+recursive(index+1,0,prices,n);
            int ignorekaro=recursive(index+1,1,prices,n);
            profit=max(buykaro,ignorekaro);
        }
        if(buy==0){
            int sellkaro=prices[index]+recursive(index+1,1,prices,n);
            int ignorekaro=recursive(index+1,0,prices,n);
            profit=max(sellkaro,ignorekaro);
        }
        return profit;
    }
    int topdowndp(int index,int buy,vector<int> &prices,int n,vector<vector<int>> &dp)
    {
        if(index>=n){
            return 0;
        }
        int profit=0;
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }
        if(buy==1){
            // two choice hai buy karo yah ignore karo
            int buykaro=-prices[index]+topdowndp(index+1,0,prices,n,dp);
            int ignorekaro=topdowndp(index+1,1,prices,n,dp);
            profit=max(buykaro,ignorekaro);
        }
        if(buy==0){
            int sellkaro=prices[index]+topdowndp(index+1,1,prices,n,dp);
            int ignorekaro=topdowndp(index+1,0,prices,n,dp);
            profit=max(sellkaro,ignorekaro);
        }
        dp[index][buy]=profit;
        return dp[index][buy];
    }
    int bottomupdp(vector<int> &prices)
    {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        
        for(int index=n-1;index>=0;index--)
        {
            for(int buy=1;buy>=0;buy--)
            {
                int profit=0;
            if(buy==1)
                {
            // two choice hai buy karo yah ignore karo
                int buykaro=-prices[index]+dp[index+1][0];
                int ignorekaro=dp[index+1][1];
                profit=max(buykaro,ignorekaro);
                }
            if(buy==0){
                int sellkaro=prices[index]+dp[index+1][1];
                int ignorekaro=dp[index+1][0];
                profit=max(sellkaro,ignorekaro);
            }
            dp[index][buy]=profit;
            }
        }
        return dp[0][1];
    }
    
    int space_optimization(vector<int>&prices)
    {
         int n=prices.size();
        
        vector<int>curr(n+1,0);
        
        vector<int>next(n+1,0);
        
        for(int index=n-1;index>=0;index--)
        {
            for(int buy=1;buy>=0;buy--)
            {
                int profit=0;
               if(buy==1)
                {
            // two choice hai buy karo yah ignore karo
                int buykaro=-prices[index]+next[0];
                int ignorekaro=next[1];
                profit=max(buykaro,ignorekaro);
                }
              if(buy==0){
                int sellkaro=prices[index]+next[1];
                int ignorekaro=next[0];
                profit=max(sellkaro,ignorekaro);
            }
            curr[buy]=profit;
            }
            next=curr;
            
        }
        return curr[1];
    }
    
   int space_optimization_1(vector<int>&prices)
   {
       int max_profit=0;
       for(int i=0;i<prices.size()-1;i++)
       {
           if(prices[i+1]>prices[i]){
               int diff=prices[i+1]-prices[i];
               max_profit=max_profit+diff;
           }
               
       }
    return max_profit;
   }
public:
    int maxProfit(vector<int>& prices)
    {
        int n=prices.size();
        // 1 indicates that sabse pahle hum stock buy karenga
        // return recursive(0,1,prices,n);

        // topdowndp 2d dp

        //we have 2 columns

        // vector<vector<int>>dp(n+1,vector<int>(2,-1));
        // return topdowndp(0,1,prices,n,dp);

        // bottomupdp

        // return bottomupdp(prices);
        
        // return space_optimization(prices);
        
        return space_optimization_1(prices);
    }
    
};