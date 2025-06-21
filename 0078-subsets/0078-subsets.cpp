class Solution {
public:
    vector<vector<int>>ans;


    void solve(vector<int>&nums,vector<int>temp,int idx)
    {
        if(idx==nums.size()){
            ans.push_back(temp);
            return ;
        }
        temp.push_back(nums[idx]);
        solve(nums,temp,idx+1);
        temp.pop_back();
        solve(nums,temp,idx+1);
        return ;

    }
    vector<vector<int>> subsets(vector<int>& nums)
    {
        // inclusion exclusion principle
        vector<int>op;
        solve(nums,op,0);
        return ans;
        
    }
};