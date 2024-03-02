class Solution {
    
public:
    
    vector<vector<int>>ans;
    
    vector<int>temp;
    
    void solve(vector<int>&nums,int index,int size)
    {
        
        if(index>=size)
        {
            ans.push_back(temp);
            return ;
        }
        // include
        
        temp.push_back(nums[index]);
        solve(nums,index+1,size);
        temp.pop_back();
        
        //exclude
        solve(nums,index+1,size);
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        int n=nums.size();
        
        vector<vector<int>>ans1;
        
        sort(nums.begin(),nums.end());
        vector<int> v;


        solve(nums,0,n);

        set<vector<int>> st;

        for(auto it:ans)
        {

            st.insert(it);

        }

        for(auto it:st){

            ans1.push_back(it);

        }

        return ans1;
        
    }
};