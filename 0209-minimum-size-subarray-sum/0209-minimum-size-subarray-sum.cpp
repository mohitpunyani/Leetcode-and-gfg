class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int n=nums.size();
        int i=0;
        int j=0;
        int s=0;
        int mn=INT_MAX;
        while(j<n)
        {
            s=s+nums[j];
            if(s<target){
                j++;
            }
            else if(s==target){
                mn=min(mn,j-i+1);
                j++;
            }
            else{
                while(s>target){
                    s=s-nums[i];
                    i++;
                    if(s==target)
                    {
                        mn=min(mn,j-i+1);
                    }
                }
                j++;
                mn=min(mn,j-i+1);
            }
        }
        return mn==INT_MAX ?0 : mn;
    }
};