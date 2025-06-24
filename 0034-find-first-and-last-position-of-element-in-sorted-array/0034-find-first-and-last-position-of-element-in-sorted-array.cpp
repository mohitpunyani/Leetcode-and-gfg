class Solution {
public:

vector<int>ans;

int  first_occurence(vector<int>&nums,int target)
{
    int ans=-1;
    int low=0;
    int high=nums.size()-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(nums[mid]<target){
            low=mid+1;
        }
        else if(nums[mid]>target){
            high=mid-1;

        }
        else{
            if(mid-1>=0 && nums[mid]==nums[mid-1])
            {
                high=mid-1;

            }
            else{
                ans=mid;
                break;
            }
        }
    }
        return ans;
}

int  second_occurence(vector<int>&nums,int target)
{
    int ans=-1;
    int low=0;
    int high=nums.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]>target){
            high=mid-1;
        }
        else if(nums[mid]<target){
            low=mid+1;
        }
        else{
            if(mid+1!=nums.size() && nums[mid]==nums[mid+1])
            {
                low=mid+1;
            }
            else{
                ans=mid;
                break;
            }
        }
    }
    return ans;


}
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int n=nums.size();
        int fst_occ=first_occurence(nums,target);
        int sec_occ=second_occurence(nums,target);
        ans.push_back(fst_occ);
        ans.push_back(sec_occ);
        return ans;
    }
         
};