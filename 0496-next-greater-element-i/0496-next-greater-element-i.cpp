class Solution {
public:
unordered_map<int,int>mp;
stack<int>st;
void ngl(vector<int>&nums1,vector<int>&nums2,int n1,int n2)
{
  
    for(int i=n2-1;i>=0;i--){
        while(!st.empty() && nums2[i]>=st.top())
        {
            st.pop();

        }
         mp[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
    }
    return ;
}

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        int n1=nums1.size();
        vector<int>ans(n1);
        int n2=nums2.size();
        ngl(nums1,nums2,n1,n2);
        for(int i=0;i<n1;i++)
        {
            ans[i]=mp[nums1[i]];
        }
        return ans;
    }
};