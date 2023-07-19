class Solution {
    private:
    int recursive(int index,int buy,vector<int> &prices,int n){
        if(index>=n)
        {
            return 0;
        }
        int profit=0;
        if(buy==1){
            // two choice hai buy karo yah ignore karo
            int buykaro=-prices[index]+recursive(index+1,0,prices,n);
            int ignorekaro=recursive(index+1,1,prices,n);
            profit=max(buykaro,ignorekaro);
        }
        else{
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
        else{
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
        dp[n][0]=0;
        dp[n][1]=0;
        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                int profit=0;
                if(buy==1)
                {
            // two choice hai buy karo yah ignore karo
                int buykaro=-prices[index]+dp[index+1][0];
                int ignorekaro=dp[index+1][1];
                profit=max(buykaro,ignorekaro);
                }
                else{
                int sellkaro=prices[index]+dp[index+1][1];
                int ignorekaro=dp[index+1][0];
                profit=max(sellkaro,ignorekaro);
                // dp[index][buy]=profit;
                 }
            dp[index][buy]=profit;
            }
        }
        return dp[0][1];
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

        return bottomupdp(prices);
    }
    
};