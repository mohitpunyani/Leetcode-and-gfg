class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
    vector<int>ans;
       unordered_map<int,int>mp;
       for(int i=0;i<nums.size();i++)
       {
        int value=target-nums[i];
        if(mp.find(value)!=mp.end())
        {
            int index=mp[value];
            ans.push_back(index);
            ans.push_back(i);

        }
        else{
            mp.insert({nums[i],i});
        }
       }
       return ans;
    }
};