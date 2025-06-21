class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>&candidates,vector<int>temp,int target,int idx)
    {
        if(target<0){
            return ;
        }
        if(target==0){
            ans.push_back(temp);
            return ;
        }
        for(int i=idx;i<candidates.size();i++)
        {
            temp.push_back(candidates[i]);
            solve(candidates,temp,target-candidates[i],i);
            temp.pop_back();

        }
        return ;


    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<int>temp;
        solve(candidates,temp,target,0);
        return ans;
    }
};