class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_map<int,int>mp;
        vector<int>ans;
        int n=nums1.size();
        int m=nums2.size();
        for(int i=0;i<n;i++)
        {
            mp[nums1[i]]++;
        }
        for(int i=0;i<m;i++){
            if(mp.find(nums2[i])!=mp.end())
            {
                if(mp[nums2[i]]>0)
                {
                    ans.push_back(nums2[i]);
                    mp[nums2[i]]--;  
                }
            }
            else{
                continue;
            }
        }
        return ans;        
    }
};