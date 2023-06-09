class Solution {
public:
    
    // based on inclusion exclusion principle
    
    int recursive(vector<int>&nums,int index)
    {
        if(index>=nums.size())
        {
            return 0;
        }
        int include=nums[index]+recursive(nums,index+2);
        int exclude=recursive(nums,index+1)+0;
        int ans=max(include,exclude);
        return ans;
        
    }
    
    int topdowndp(vector<int>&dp,vector<int>&nums,int index)
    {
        if(index>=nums.size())
        {
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int include=nums[index]+topdowndp(dp,nums,index+2);
        int exclude=topdowndp(dp,nums,index+1)+0;
        int ans=max(include,exclude);
        dp[index]=ans;
        return dp[index];
    }
    
    int bottomupdp(vector<int>&nums)
    {
        int n=nums.size();
        
        if(n==1){
            return nums[0];
        }
        vector<int>dp(n,0);
        
        dp[0]=nums[0];
        
        dp[1]=max(nums[0],nums[1]);
        
        for(int i=2;i<n;i++)
        {
            // for size 3 
            
            int include=dp[i-2]+nums[i];
            
            int exclude=dp[i-1]+0;
            
            dp[i]=max(include,exclude);
        }
        return dp[n-1];
    }
    
    int space_optimization(vector<int>&nums)
    {
        int n=nums.size();
         if(n==1){
            return nums[0];
        }
        int prev1=nums[0];
        
        int prev2=max(nums[0],nums[1]);
        
        for(int i=2;i<n;i++){
            
            
            int include=prev1+nums[i];
            
            int exclude=prev2+0;
            int ans=max(include,exclude);
            
            prev1=prev2;
            
            prev2=ans;
        }
        return prev2;
        
    }
    int rob(vector<int>& nums)
    {
        // return recursive(nums,0);
        
        // vector<int>dp(nums.size()+1,-1);
        // return topdowndp(dp,nums,0);
        
        
        // bottomupdp
        
        // return bottomupdp(nums);
        
        return space_optimization(nums);
        
    }
};