class Solution {
public:
stack<int>st;
void solve(vector<int>&nums,vector<int>&ans,bool &check,int n)
{
    int i;
    for(i=n-1;i>=0;i--)
    {
        while(!st.empty() && nums[i]>=st.top())
        {
            st.pop();

        }
        if(!st.empty()){
            ans[i]=st.top();
        }
        st.push(nums[i]);
    }
    if(check==true){
        check=false;
        solve(nums,ans,check,n);
        return ;
    }
    return ;
}

    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>ans(n,-1);
        bool check=true;
        solve(nums,ans,check,n);
        return ans;
        
    }
};