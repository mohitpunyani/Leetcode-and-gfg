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
        
         if(n==1)
         {
            return nums[0];
         }
        vector<int>dp(n,0);
            
        dp[0]=nums[0];
        
        dp[1]=max(nums[0],nums[1]);
    
        for(int i=2;i<n;i++)
        {
            int include=dp[i-2]+nums[i];
            
            int exclude=dp[i-1]+0;
            
            int ans=max(include,exclude);
            
            dp[i]=ans;
        }
        
        // dp[n-1]=max(dp[n-2],dp[n-3]);
        return dp[n-1];
        
    }
    
    int space_optimization(vector<int>&nums)
    {
        int n=nums.size();
        
        if(n==1){
            return nums[0];
        }
        if(n==2)
        {
            return max(nums[0],nums[1]);
        }
        
        int prev_1=nums[0];  // works like include
        
        int prev_2=max(nums[0],nums[1]);  // works like exclude
        
        int ans;
        
        
        for(int i=2;i<n;i++)
        {
            int include=prev_1+nums[i];
            
            int exclude=prev_2;
            
            ans=max(include,exclude);
        
            prev_1=prev_2;
            
            prev_2=ans;        
        }
        return ans;
    }
    int rob(vector<int>& nums) 
    {
        // RECURSIVE
        
        // return solve(nums,0);
        
        // TOPDOWN
        
        // int n=nums.size();
        
        // vector<int>dp(n,-1);
            
        // return topdowndp(nums,0,dp);
    
        
        // return bottomupdp(nums);
        
        
        return space_optimization(nums);
        
        
    }
};