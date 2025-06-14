class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
          int n=nums.size();
        int curr_sum=0;
        int mx=INT_MIN;
        for(int i=0;i<n;i++)
        {
            curr_sum=max(curr_sum+nums[i],nums[i]);
            mx=max(mx,curr_sum);
            
        }
        return mx;
    }
};