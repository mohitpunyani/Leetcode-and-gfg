class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int n=nums.size();
        int total_sum=0;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            total_sum=total_sum+nums[i];
        }
        for(int i=0;i<=n;i++)
        {
            sum=sum+i;

        }
        int ans=sum-total_sum;
        return ans;
    }
};