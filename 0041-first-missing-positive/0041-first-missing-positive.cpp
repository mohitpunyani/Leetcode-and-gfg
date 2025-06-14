class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        int n=nums.size();
        unordered_map<int,int>mp;
       
        for(int i=0;i<n;i++)
        {
            mp.insert({nums[i],i});
        }
        int ans=0;
        
        int i=1;
        for(i=1;i<=n;i++){
            if(mp.find(i)==mp.end())
            {
                ans=i;
                // break; // because we need first missing positive number
                return ans;
            }
            else{
                continue;
            }
        }
        
        return i;
    }
};