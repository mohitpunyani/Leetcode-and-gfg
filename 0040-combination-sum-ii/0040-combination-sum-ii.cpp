class Solution {
public:
    
    void solve(int index,int k,vector<int>&arr,vector<int>&temp,vector<vector<int>>&ans)
{
    if(k<0){
        return ;
        
    }
    if(k==0){
        ans.push_back(temp);
        return ;
    }
    for(int i=index;i<arr.size();i++)
    {
        if(i>index && arr[i]==arr[i-1]) 
            continue;

        if(arr[i]>k){
            break;
            // iska matlab hai ki aage wali values ke liye bhi solution nahi hai 
        }
        else{
        temp.push_back(arr[i]);
        solve(i+1,k-arr[i],arr,temp,ans);
        temp.pop_back();
    }
    }
    return ;
    
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        int k=target;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        solve(0,k,candidates,temp,ans);
        // ans.erase(unique(ans.begin(),ans.end()),ans.end());
        // ans.resize(unique(ans.begin(),ans.end())-ans.begin());
        // A.erase(unique(A.begin(), A.end()), A.end()); // remove duplicate elements

        return ans;
    }
};