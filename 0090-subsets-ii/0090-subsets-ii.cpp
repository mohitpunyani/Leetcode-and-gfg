class Solution {
public:

   set<vector<int>>st;

    void solve(vector<int>&nums,vector<int>temp,int idx)
    {
        if(idx==nums.size())
        {
            st.insert(temp);
            return ;
        }
        temp.push_back(nums[idx]);
        solve(nums,temp,idx+1);
        temp.pop_back();
        solve(nums,temp,idx+1);
        return ;

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        vector<int>op;
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        solve(nums,op,0);
        for(auto it:st)
        {
            ans.push_back(it);
        }
        // solve(nums,op,0);
        return ans;
    }
};