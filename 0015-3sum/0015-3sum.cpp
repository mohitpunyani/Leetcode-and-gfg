class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // one way to write the code
        int n=nums.size();
        if(n<3) return {};
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        // i ko fix kar diya j or k ko move kiya
        for(int i=0;i<n-1;i++)  //i++
        {
            if(i==0 || nums[i]!=nums[i-1]) // it is also important condition
            {
                
            int j=i+1;
            int k=n-1;
            while(j<k)// j<=k is wrong j and k can't be point to same numbers
            {
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0)
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(j<k && nums[j]==nums[j+1]) 
                        j++;
                    while(j<k && nums[k]==nums[k-1])
                        k--;
                    j++;
                    k--;
                    
                    
                }
                    else if (sum>0) k--;
                    else j++;
        
            }
                
        }
    }
        return ans;
        
    }
};