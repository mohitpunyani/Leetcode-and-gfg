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
    int rob(vector<int>& nums)
    {
        // return recursive(nums,0);
        
        vector<int>dp(nums.size()+1,-1);
        return topdowndp(dp,nums,0);
        
        
    }
};