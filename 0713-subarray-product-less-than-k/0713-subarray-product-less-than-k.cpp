class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k)
    {
        int i=0;
        int j=0;
        int n=nums.size();
        int count=0;
        long long int prod=1;
        if(k<=1)
        {
            return 0;
        }
        while(j<n)
        {
            prod=prod*nums[j];
            if(prod<k)
            {
                count=count+(j-i+1);
                j++;
            }
            else{
                while(prod>=k)
                {
                    prod=prod/nums[i];
                    i++;
                    // if(prod<=k){
                    //     count=count+(j-i+1);
                    // }
                }
                count=count+(j-i+1);
                j++;
            }
        }
        return count;
    }
};