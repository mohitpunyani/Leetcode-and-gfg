class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums)
    {
        // brute force
        vector<int>pos;
        vector<int>neg;
        vector<int>ans;
        int sz=nums.size();
        for(int i=0;i<sz;i++){
            if(nums[i]>=0){
                pos.push_back(nums[i]);
            }
        }
        for(int i=0;i<sz;i++){
            if(nums[i]<0){
                neg.push_back(nums[i]);
            }
        }
        sz=pos.size();
        for(int i=0;i<sz;i++)
        {
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);

        }
        return ans;
    }
};