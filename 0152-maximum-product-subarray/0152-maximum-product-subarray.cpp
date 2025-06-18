class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int n=nums.size();
        int pre=1;
        int mx1=INT_MIN;
        int mx2=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(pre==0){
                pre=1;
            }
            pre=pre*nums[i];
            mx1=max(mx1,pre);
        }
        int suff=1;
        for(int i=n-1;i>=0;i--){
            if(suff==0){
                suff=1;
            }
            suff=suff*nums[i];
            mx2=max(mx2,suff);
        }
        int ans;
        ans=max(mx1,mx2);
        return ans;
      
    }
};