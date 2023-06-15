class Solution {
public:
    bool find132pattern(vector<int>& nums)
    {
        // IT'S A VERY EASY QUESTION JUST OBSERVE CAREFULLY
        
        int second=INT_MIN;
        int n=nums.size();
        
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            if(second>nums[i]){
                return true;
            }
            while(!st.empty() && nums[i]>st.top())
            {
            
                second=st.top();
                st.pop();
            }
            st.push(nums[i]);
            
            
        }
        return false;
        
        // 2ND APPROACH 
        
        
          // int n=nums.size();
        // int m=nums[0];
        // for(int j=1;j<n;j++)
        // {
        //     for(int k=j+1;k<n;k++)
        //     {
        //         if(nums[k]>m && nums[j]>nums[k])return true;
        //         m=min(m,nums[j]);
        //     }
        // }
        // return false;
    }
};