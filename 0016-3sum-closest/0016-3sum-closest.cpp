class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        sort(nums.begin(),nums.end());
        int closest_sum=nums[0]+nums[1]+nums[2];
        int n=nums.size();
        for(int i=0;i<=nums.size()-3;i++){
            int low=i+1;
            int high=n-1;
            while(low<high)
            {
                int sum=nums[i]+nums[low]+nums[high];
                if(sum==target)
                {
                    return sum;

                }
               if(abs(target-sum)<abs(target-closest_sum))
               {
                closest_sum=sum;
               }
               if(sum>target){
                high--;
               }
               else{
                low++;
               }
            }
        }
        return closest_sum;
        
    }
};