//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    
       void solve(int i,vector<int>& nums, vector<int> &v, vector<vector<int>> &ans){

        if(i>=nums.size()){

            ans.push_back(v);

            return;

        }

        v.push_back(nums[i]);

        solve(i+1,nums,v,ans);

        v.pop_back();

        solve(i+1,nums,v,ans);

    }
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        // code here 
        vector<vector<int>> ans;

        vector<int> v;

        sort(arr.begin(),arr.end());

        solve(0,arr,v,ans);

        

        set<vector<int>> st;

        for(auto it:ans){

            st.insert(it);

        }
        ans.clear();

        for(auto it:st){

            ans.push_back(it);

        }

        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   



// } Driver Code Ends