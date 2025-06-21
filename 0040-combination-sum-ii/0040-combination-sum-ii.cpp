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
             if(i > idx && candidates[i] == candidates[i-1]) continue;
            temp.push_back(candidates[i]);
            solve(candidates,temp,target-candidates[i],i+1);
            temp.pop_back();

        }
        return ;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(),candidates.end());
        vector<int>temp;
        solve(candidates,temp,target,0);
        // set<vector<int>>st;
        // for(auto it:ans)
        // {
        //     st.insert(it);
        // }
        // ans.resize(0);
        // for(auto it:st){
        //     ans.push_back(it);
        // }     
        // ans.erase(unique(ans.begin(), ans.end()), ans.end()); // remove duplicate elements

        return ans;
        
    }
};