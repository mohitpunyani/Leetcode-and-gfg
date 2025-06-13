class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        set<int>st;
        vector<int>ans;
        int n=nums1.size();
        int m=nums2.size();
        for(int i=0;i<n;i++)
        {
            st.insert(nums1[i]);
        }
        for(int i=0;i<m;i++){
            if(st.find(nums2[i])!=st.end())
            {
                auto it=st.find(nums2[i]);
                ans.push_back(nums2[i]);
                st.erase(it);
            }
        }
        return ans;
    }
};