class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums)
    {
        int n=nums.size();
        long long int ans=0;
        long long int count_0=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                count_0++;
                ans=ans+count_0;
            }
            else{
                count_0=0;
            }
        }
        return ans;
    }
};