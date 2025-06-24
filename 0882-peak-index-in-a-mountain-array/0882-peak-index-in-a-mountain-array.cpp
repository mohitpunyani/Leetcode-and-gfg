class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr)
    {
        vector<int>nums(arr);
         int low=0;
        int high=arr.size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
            {
                return mid;

            }

            else if(nums[mid]>nums[mid-1]){
                low=mid+1;
            }
            else if(nums[mid]>nums[mid+1]){
                high=mid;
            }
        }
        
        return -1;
    }
};