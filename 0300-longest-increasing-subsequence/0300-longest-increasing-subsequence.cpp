class Solution {
    private:
    int recursive(vector<int> &nums,int prev,int curr){
        if(curr>=nums.size()){
            return 0;
        }
        int include=0;
        if(prev==-1 || nums[curr]>nums[prev]){
            include=1+recursive(nums,curr,curr+1);
        }
        int exclude=0+recursive(nums,prev,curr+1);
        int ans=max(include,exclude);
        return ans;
    }

      int topdowndp(vector<int> &nums,int prev,int curr,vector<vector<int>> &dp){
        if(curr>=nums.size()){
            return 0;
        }
        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }
        int include=0;
        if(prev==-1 || nums[curr]>nums[prev]){
            include=1+topdowndp(nums,curr,curr+1,dp);
        }
        int exclude=0+topdowndp(nums,prev,curr+1,dp);
        int ans=max(include,exclude);
        dp[curr][prev+1]=ans;
        return dp[curr][prev+1];
        
    }
    int bottomupdp(vector<int>&nums){
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--)
            {
                int include=0;
                if(prev==-1 || nums[curr]>nums[prev])
                {
                    include=1+dp[curr+1][curr+1];
                }
                int exclude=0+dp[curr+1][prev+1];
                int ans=max(include,exclude);
                dp[curr][prev+1]=ans;

                
            }
        }
        return  dp[0][0];
    }
    // we can also solve this using two one-d arrays

    int bottomupdp2(vector<int> &nums)
    {
        int n=nums.size();

        vector<int>prevrow(n+1,0);
        vector<int>currrow(n+1,0);
           for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--)
            {
                int include=0;
                if(prev==-1 || nums[curr]>nums[prev])
                {
                    include=1+prevrow[curr+1];
                }
                int exclude=0+prevrow[prev+1];
                int ans=max(include,exclude);
                currrow[prev+1]=ans;  
            }
            // updation
            prevrow=currrow;
        }
        return  prevrow[0];
    }
    int binarysearch(vector<int> &nums){

        // first element toh hamesha hoga hi
        int n=nums.size();
        if(n==0){
            return 0;
        }
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            // agar aapka curr pieche wala element se bada hua toh answer me push kar do
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                // agar nahi hai toh find just greater element in ans using concept of lower_bound;
                int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[index]=nums[i];
            }
        }
        return ans.size();
    }
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        // return recursive(nums,-1,0);

        // topdowndp
        int n=nums.size();
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // return topdowndp(nums,-1,0,dp);

        // bottomupdp
        // return bottomupdp(nums);

        // return bottomupdp2(nums);

        return binarysearch(nums);
        
    }
};