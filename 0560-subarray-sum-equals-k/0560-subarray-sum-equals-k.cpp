class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        int n=nums.size();
        vector<int>prefix_sum(n);
        prefix_sum[0]=nums[0];
        unordered_map<int,int>mp;
        for(int i=1;i<n;i++)
        {
            prefix_sum[i]=prefix_sum[i-1]+nums[i];
        }
        int count=0;

        for(int i=0;i<n;i++)
        {
            int diff=prefix_sum[i]-k;
            if(prefix_sum[i]==k){
                count+=1;
            }
            if(mp.find(diff)!=mp.end())
            {
                count=count+mp[diff];
            }
            mp[prefix_sum[i]]++;

        }
        return count;

        
    }
};