class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
       int n=nums.size();
       sort(nums.begin(),nums.end());
         set<vector<int>> s;
       for(int i=0;i<=n-3;i++)
       {
        if(i>0 && nums[i] == nums[i - 1]) continue;
        int start=i+1;
        int end=n-1;
        while(start<end)
        {
            int sum=nums[i]+nums[start]+nums[end];
            if(sum==0)
            {
                // vector<int>temp;
                // temp.push_back(nums[i]);
                // temp.push_back(nums[start]);
                // temp.push_back(nums[end]);
                // ans.push_back(temp);

                // start++;
                // end--;

                // to handle duplicates

                // while(start < end && nums[start] == nums[start - 1]) start++;
                // while(start < end && nums[end] == nums[end + 1]) end--;

                // another way to handle duplicate using set

                s.insert({nums[i], nums[start], nums[end]});
                start++;
                end--;

            }
            else if(sum>0)
            {
                end--;
            }
            else{
                start++;

            }
        }
       }
       for(auto a:s){
        ans.push_back(a);
       }
       return ans;

    }
};