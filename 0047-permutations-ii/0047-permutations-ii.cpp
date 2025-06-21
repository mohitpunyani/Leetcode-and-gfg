class Solution {
public:
 vector<vector<int>> ans;
    void solve(vector<int>& nums, int index)
     {
        if (index >= nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            swap(nums[i], nums[index]);
            solve(nums, index + 1);
            swap(nums[i], nums[index]); // backtrack
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        
        solve(nums,0);
        set<vector<int>>st;
        for(auto it:ans){
            st.insert(it);
        }
        ans.resize(0);
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
        
    }
};