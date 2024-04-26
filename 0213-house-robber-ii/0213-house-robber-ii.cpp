class Solution {
public:
    
    int rec(vector<int>&nums,int index,int size)
    {
        if(index>size)
        {
            return 0;
        }
        
        int include=rec(nums,index+2,size)+nums[index];
        int exclude=rec(nums,index+1,size)+0;
        
        int ans=max(include,exclude);
        
        return ans;
    }
    
    int topdowndp(vector<int>&nums,vector<int>&dp,int index,int size)
    {
        
        if(index>size)
        {
            return 0;
        }
        
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        int include=topdowndp(nums,dp,index+2,size)+nums[index];
        int exclude=topdowndp(nums,dp,index+1,size)+0;
        
        int ans=max(include,exclude);
        
        dp[index]=ans;
        
        return dp[index];
    }
    int rob(vector<int>& nums)
    {
        //  recursive
        
        int n=nums.size();
        if(n==1)
        {
            return nums[0];
        }
//         int a1=rec(nums,0,n-2);
//         int a2=rec(nums,1,n-1);
        
//         int ans=max(a1,a2);
        
//         return ans;
        
        
        // topdowndp
        
        vector<int>dp1(n+1,-1);
        
        vector<int>dp2(n+1,-1);
        
        int a1=topdowndp(nums,dp1,0,n-2);
        
        int a2=topdowndp(nums,dp2,1,n-1);
        
        int ans=max(a1,a2);
        
        return ans;
    }
};