class Solution {
public:
    void reverse(vector<int>&nums,int low,int high)
    {
        while(low<=high)
        {
            
            int temp=nums[low];
            nums[low]=nums[high];
            nums[high]=temp;
            low++;
            high--;
            
        }
    }
    void rotate(vector<int>& nums, int k)
    {
        
        int n=nums.size();
        k=k%n;
        if(k>=n){
            return ;
        }
        reverse(nums,0,n-1);
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);
        return ;
    }
};