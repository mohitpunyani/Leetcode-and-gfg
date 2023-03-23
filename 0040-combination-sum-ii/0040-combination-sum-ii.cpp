
class Solution {
public:
    void solve(vector<int> arr,vector<vector<int>> &ans,vector<int>& tmp,int k,int s,int& n){
        if(s>n)return;
        if(k==0){
            ans.push_back(tmp);
            return;
        }
        if(k<0){
            return;
        }
        for(int i = s; i < n; i++){
            tmp.push_back(arr[i]);
            solve(arr,ans,tmp,k-arr[i],i+1,n);
            while(i<n-1 && arr[i]==arr[i+1])
                i++;
            tmp.pop_back();
        }
        return ;
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int &k) {
        vector<vector<int>>ans;
        vector<int>temp;
        int n = arr.size();
        sort(arr.begin(),arr.end());
        solve(arr,ans,temp,k,0,n);
        return ans;
    }
};