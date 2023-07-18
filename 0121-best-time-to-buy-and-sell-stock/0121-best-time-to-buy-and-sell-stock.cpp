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
    

    int maxProfit(vector<int>& prices)
    {
        // WE HAVE TO PLAY WITH A BOOLEAN VARIABLE THAT INDICATES BUY AND SELL
        
        // RECURSIVE
        
        // we can do atmost k transactions
        
        int n=prices.size();
        // return recursive(0,1,1,prices,n);
        
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return topdowndp(0,1,1,prices,n,dp);
        
    }
};