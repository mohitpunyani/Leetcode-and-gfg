class Solution
{
    public:
        vector<vector < int>> ans;
    vector<int> temp;
    void solve(vector<int> &nums, int index)
    {

        if (index >= nums.size())
        {
            ans.push_back(temp);
           	return;
        }

       	// inclusion
        temp.push_back(nums[index]);
        solve(nums, index + 1);
       	// exclusion
        temp.pop_back();
        solve(nums,index+1);
    }

vector<vector < int>> subsets(vector<int> &nums)
{
   	// solve using choice diagram using inclusion exclusion principle
    solve(nums, 0);
    return ans;
}
};