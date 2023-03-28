
    class Solution {
public:
    int recursive(vector<int> &days,vector<int> &cost,int index ,int n)
    {
        // base case
        if(index>=n){
            return 0;
        }
        // we have to do three recursive call , one for one day pass , second for 7 day pass, 
        // third for 30 days pass
        
        // one day pass
        
        int option1=cost[0]+recursive(days,cost,index+1,n);
        
        // 7 days pass
        int i;
        for(i=index;i<n  && days[i]<days[index]+7 ;i++);
        
        
        // now i becomes our new index
        
       int option2=cost[1]+recursive(days,cost,i,n);
        
        // 30 days pass
        
        for(i=index; i<n && days[i]<days[index]+30;i++);
        int option3=cost[2]+recursive(days,cost,i,n);
        
        int ans=min(option1,min(option2,option3));
        return ans;
        
    }
      int topdowndp(vector<int> &days,vector<int> &cost,int index ,int n,vector<int> &dp)
    {
        // base case
        if(index>=n)
        {
            return 0;
        }
         if(dp[index]!=-1){
             return dp[index];
         }
        // we have to do three recursive call , one for one day pass , second for 7 day pass, 
        // third for 30 days pass
        
        // one day pass
        
        int option1=cost[0]+topdowndp(days,cost,index+1,n,dp);
        
        // 7 days pass
        int i;
        for(i=index;i<n  && days[i]<days[index]+7 ;i++);
        
        
        // now i becomes our new index
        
       int option2=cost[1]+topdowndp(days,cost,i,n,dp);
        
        // 30 days pass
        
        for(i=index; i<n && days[i]<days[index]+30;i++);
        int option3=cost[2]+topdowndp(days,cost,i,n,dp);
        
        int ans=min(option1,min(option2,option3));
        dp[index]=ans;
        return dp[index];
      }
    int bottomupdp(vector<int> &days,vector<int> &cost, int n)
    {
        vector<int> dp(n+1,INT_MAX);
        dp[n]=0;
        
        for(int k=n-1;k>=0;k--)
        {
            int option1= cost[0]+dp[k+1];
            
            // 7 days pass
            int i;
            for(i=k;i<n && days[i] <days[k]+7;i++);
            // now i becomes our new index.
            int option2=cost[1] + dp[i];
            
            // 30 days pass
            
            for(i=k;i<n && days[i]<days[k]+30;i++);
            int option3=cost[2]+dp[i];
            
            dp[k]=min(option1,min(option2,option3));
            
        }
        return dp[0];
        
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs)
    {
        int n=days.size();
        // return recursive(days,costs,0,n);
        vector<int> v(n+1,-1);
        // int ans=topdowndp(days,costs,0,n,v);
        
        int ans=bottomupdp(days,costs,n);
        return ans;

    }
};
