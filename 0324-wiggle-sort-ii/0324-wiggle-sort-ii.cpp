class Solution {
public:
    void wiggleSort(vector<int>& nums)
    {
        int n=nums.size();
        vector<int>ans(n);
        int j=1;
        sort(nums.begin(),nums.end());
        int mid=n/2;
        if(n%2!=0)
        {
            mid=mid+1;
            
        }

        for(int i=n-1;i>=mid;i--)
        {
            
            ans[j]=nums[i];
            j=j+2;
        }
       j=0;
        for(int i=mid-1;i>=0;i--)
        {
            if(j>=n){
             return ;
            }
            ans[j]=nums[i];
            j=j+2;

        }
        nums=ans;
    }
};