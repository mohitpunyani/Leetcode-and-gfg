class Solution {
public:
    vector<vector<int>>ans;
    void solve(int k,int tar,vector<int>temp,int idx)
    {
        if(tar<0){
            return ;
        }

        if(k==0 && tar==0)
        {
            ans.push_back(temp);
            return ;
        }

        for(int i=idx;i<=9;i++)
        {
            temp.push_back(i);
            solve(k-1,tar-i,temp,i+1);
            temp.pop_back();
            // solve(k,tar,temp,i+1);  // backtrack

        }
        return ;

    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int>temp;
        int tar=n;
        solve(k,tar,temp,1);
        return ans;
    }
};


// class Solution {
// public:
//     vector<vector<int>> ans;
//     // int k;
//     void solve(vector<int> temp, int tar, int idx,int k) {
//         if(tar < 0)
//            return;
//         if(temp.size() == k && tar==0) {
//             ans.push_back(temp);
//             return;
//         }
//         temp.push_back(idx);
//         for(int i=idx; i<=9; i++) 
//         {
//                 solve(temp, tar-i, i+1,k);
//                 temp.pop_back();
//                 solve(temp,tar,i+1,k);
//         }
//     }
//     vector<vector<int>> combinationSum3(int k, int n) {
//         int tar=n;
//         vector<int>temp;
//         solve(temp, n, 1,k);
//         return ans;
//     }
// };