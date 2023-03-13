

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        // map me store kar liya first element and difference of target and first element 
        // which will give you the second element target we get
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            int  y=target-nums[i];
            if(mp.find(y)!=mp.end())
            {
                ans.push_back(i);
                ans.push_back(mp[y]);
                break;
            }
            else{
                mp[nums[i]]=i;
            }
            
        }
        return ans;
        
    }
};
