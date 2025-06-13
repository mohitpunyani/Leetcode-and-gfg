class Solution {
public:
    void wiggleSort(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=1;
        int j=n-1;
        vector<int>ans(n);
        
        while(i<n)
        {
            // first fill maximum values.
            ans[i]=nums[j];
            i=i+2;
            j--;
        }
        i=0;
        while(i<n){
            ans[i]=nums[j];
            i=i+2;
            j--;
        }
        nums=ans;
    }
};