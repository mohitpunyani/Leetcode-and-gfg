// class Solution
// {
//     public:
//         vector<vector < int>> ans;
//     vector<int> temp;
//     void solve(vector<int> &nums, int index)
//     {

//         if (index >= nums.size())
//         {
//             ans.push_back(temp);
//             return;
//         }
//         for (int i = index; i < nums.size(); i++)
//         {
//             // inclusion
//             temp.push_back(nums[i]);
//             solve(nums, index + 1);
//             // exclusion
            
//             temp.pop_back();
//         }
//         return;
//     }
//     vector<vector < int>> subsets(vector<int> &nums)
//     {
//        	// solve using choice diagram using inclusion exclusion principle
//         solve(nums, 0);
//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>>ans;
    void backtrack(vector<int>&arr,int start,vector<int>&temp){
        ans.push_back(temp);
        for(int i=start;i<arr.size();i++){
            temp.push_back(arr[i]);
            backtrack(arr,i+1,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& arr) {
        int n=arr.size();
        vector<int>temp;
        backtrack(arr,0,temp);
        return ans;
    }
};
