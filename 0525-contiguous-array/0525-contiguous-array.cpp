class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp; mp[0]=-1;
        int sum = 0,longest_subarray = 0;
        for(int i = 0; i < nums.size(); i++)
        {
             nums[i]=nums[i] == 0 ? - 1 : 1;    
             sum=sum+nums[i];
            if(mp.find(sum) != mp.end())
            {
                if(longest_subarray < i - mp[sum])
                {
                    longest_subarray = i - mp[sum];
                }
            }
            else
            {
                mp[sum] = i;
            }
        }
        return longest_subarray;
    }
};