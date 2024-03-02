

class Solution {
public:
    
    vector<vector<int>>res;
    void dfs(vector<int> &nums, int index, vector<int>&curr)
    {
        if(index>nums.size())
        {
            return ;
        }
        res.push_back(curr);
        for(int i=index; i<nums.size();i++)
        {
            curr.push_back(nums[i]);
            dfs(nums,i+1,curr);
            curr.pop_back();
        }
    }
     vector<vector<int>> subsets(vector<int>& nums) {
        // vector<vector<int>> res;
        vector<int> curr;
        dfs(nums,0,curr);
        return res;
       
    }

};