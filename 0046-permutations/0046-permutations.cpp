class Solution {
    private:
    void solve(int index,vector<int> &nums,vector<vector<int> > &ans){
        if(index==nums.size())
        {
            ans.push_back(nums);
            return ;
        }
        for(int j=index;j<nums.size();j++)
        {
            // ek case solve kar diya baaki recursion sambhal lega
            swap(nums[index],nums[j]);
            solve(index+1,nums,ans);
            
            // backtrack
            swap(nums[index],nums[j]);
        }
        return ;
    }
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> ans;
        solve(0,nums,ans);
        return ans;
    }
};