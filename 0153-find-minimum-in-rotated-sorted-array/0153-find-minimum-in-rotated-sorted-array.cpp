class Solution {
public:
    int findMin(vector<int>& nums) {
//        sort(nums.begin(),nums.end());

//         return nums[0];
        
        // linear search
        
        // int ans=nums[0];
        // for(int i=0;i<nums.size()-1;i++){
        //     if(nums[i]>nums[i+1]){
        //         ans=nums[i+1];
        //         break;
        //     }
        // }
        
        // return ans;
        
        // binary search
        
        // good code
        
        int l = 0, h = nums.size()-1, mid;
        if(nums.size()==1){
            return nums[0];
        }
        

         if (nums[l] < nums[h]) // this condition is for sorted array.
                return nums[l];
        while (l < h)
        {
            mid = l+(h-l)/2;
            // last wala index bhi bada hua it means the arry is sorted.
            
            if (nums[l] < nums[h]) // this condition is for sorted array.
                return nums[l];
            
            // if (nums[mid] > nums[h])
            if(nums[mid]>=nums[l])
                l = mid+1;
            else if(nums[mid]<nums[l])
                h = mid;
            
        }
        return nums[l];
        
        // another way to write binary search
        
        
        // my solution
        
        
//         int l = 0,r=nums.size()-1,n=nums.size();
//         int mid,prev,next;
//         if(n==1){
//             return nums[0];
//         }
//         while(l<=r){
            
//             mid = l + (r-l)/2;
//             prev = (mid + n - 1)%n;
//             next = (mid+1)%n;
            
//             if(nums[mid]<nums[prev] && nums[mid]<nums[next])
//                 return nums[mid];
//             else if(nums[mid]>nums[r])
//                 l = mid+1;
//             else
//                 r = mid-1;
//         }
//         return -1;
        
        
        
//                  int low=0,high = nums.size()-1;
//         while(low<high){
            
//             int mid = low +(high-low)/2;
            
//             if(nums[mid]<nums[high]){
//                 high = mid;
//             }
//             else if (nums[mid]>nums[high]){
//                 low=mid+1;
                
//             }
//             // else if(nums[mid]==nums[high])
//             // {
//             //     high--;
//             // }
//         }
        
//         return nums[high];
    }
};