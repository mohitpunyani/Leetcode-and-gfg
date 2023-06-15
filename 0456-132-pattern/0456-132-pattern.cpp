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
        
    }
};