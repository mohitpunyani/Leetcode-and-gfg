class Solution {

    public:
    
    int solve(vector<int>&nums,int index)
    {
        if(index>=nums.size())
        {
            return 0;
        }
        
        int include=solve(nums,index+2)+nums[index];
        
        int exclude=solve(nums,index+1)+0;
        
        int ans=max(include,exclude);
        
        return ans;
    }
    
    int topdowndp(vector<int>&nums,int index,vector<int>&dp)
    {
        
        if(index>=nums.size())
        {
            return 0;
        }
         
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        
        int include=topdowndp(nums,index+2,dp)+nums[index];
        
        int exclude=topdowndp(nums,index+1,dp)+0;
        
        int ans=max(include,exclude);
        
        dp[index]=ans;
        
        return dp[index];
    }
    
    int bottomupdp(vector<int>&nums)
    {
        int n=nums.size();
        
        vector<int>dp(n,0);
            
        dp[0]=nums[0];
        
        dp[1]=max(nums[0],nums[1]);
    
        for(int i=2;i<n;i++)
        {
            int include=dp[i-2]+nums[0];
            
            int exclude=dp[i-1]+0;
            
            int ans=max(include,exclude);
            
            dp[i]=ans;
        }
        
        
        return dp[n-1];
        
    }
    int rob(vector<int>& nums) 
    {
        // RECURSIVE
        
        // return solve(nums,0);
        
        // TOPDOWN
        
        int n=nums.size();
        
        vector<int>dp(n,-1);
            
        return topdowndp(nums,0,dp);
    
        
        
    }
};