class Solution {
    
public:
    
       void solve(int i,vector<int>& nums, vector<int> &v, vector<vector<int>> &ans){

        if(i>=nums.size()){

            ans.push_back(v);

            return;

        }

        v.push_back(nums[i]);

        solve(i+1,nums,v,ans);

        v.pop_back();

        solve(i+1,nums,v,ans);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> ans,ans1;

        vector<int> v;

        sort(nums.begin(),nums.end());

        solve(0,nums,v,ans);

        

        set<vector<int>> st;

        for(auto it:ans){

            st.insert(it);

        }

        for(auto it:st){

            ans1.push_back(it);

        }

        return ans1;
        
    }
};