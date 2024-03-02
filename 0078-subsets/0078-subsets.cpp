class Solution {
public:
    
    
    vector<vector<int>>ans;
    vector<int>temp;
    void subsets(vector<int>&nums,int index,int size)
    {
        
        if(index>=size)
        {
            ans.push_back(temp);
            return ;
        }
        // include
        temp.push_back(nums[index]);
        subsets(nums,index+1,size);
        temp.pop_back();
        subsets(nums,index+1,size);
        return;
        
    }
    vector<vector<int>> subsets(vector<int>& nums)
    {
        int n=nums.size();
        subsets(nums,0,n);
        return ans;
    }
};