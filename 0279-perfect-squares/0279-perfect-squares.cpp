class Solution {
public:
    int recursive(int n){
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        
        int temp=INT_MAX;
        for(int i=1;i<=sqrt(n);i++)
        {
            int square=i*i;
            int ans=recursive(n-square);
            temp=min(temp,1+ans);
        }
        return temp;
    }   
    int topdowndp(vector<int>&dp,int n){
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        
        if(dp[n]!=-1){
            return dp[n];
        }
        int temp=INT_MAX;
        for(int i=1;i<=sqrt(n);i++)
        {
            int square=i*i;
            int ans=topdowndp(dp,n-square);
            temp=min(temp,1+ans);
        }
        dp[n]=temp;
        return temp;
    }
    int numSquares(int n) 
    {
        // return recursive(n);
        
        vector<int>dp(n+1,-1);
        
        return topdowndp(dp,n);
        
    }
};