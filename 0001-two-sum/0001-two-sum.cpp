class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {

        for (size_t i = 0; i < nums.size(); i++)
         {
            for(size_t j =1; j < nums.size(); j++)
            {
                if ((nums[i] + nums[j]) == target && i != j) 
                {
                    return {static_cast<int>(i), static_cast<int>(j)};
                }
            }
        }
        return {};
    }
};