

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int,int>mp;
        
        vector<int>ans;
        
        for(int i=0;i<nums.size();i++)
        {
            int y=target-nums[i];
            if(mp.find(y)!=mp.end())
            {
                int index=mp[y];
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