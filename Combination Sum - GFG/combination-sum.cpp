//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    
    void solve(vector<int>&A,int s,int sum,vector<int>&temp,vector<vector<int>>&ans){
        
        if(sum==0){
            ans.push_back(temp);
            return ;
        }
        
        if(sum<0){
            return ;
        }
        
        for(int i=s;i<=A.size()-1;i++){
           temp.push_back(A[i]);
           solve(A,i,sum-A[i],temp,ans);
           temp.pop_back();
        }
        return;
        
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) 
    {
        // Your code here 
        
        // // we are hret o do so that there is not a god deal iwht out 
        
        sort(A.begin(),A.end());
        vector<int>temp;
        vector<vector<int>>ans;
          A.resize(unique(A.begin() , A.end())-A.begin());
        // A.erase(unique(A.begin(), A.end()), A.end()); // remove duplicate elements
        sort(ans.begin(),ans.end());
        solve(A,0,B,temp,ans);
        // for(int i=0;i<ans.size();i++){
        //     sort(ans[i].begin(),ans[i].end());
        // }
        // set<vector<int>>st;
        // for(auto x:ans){
        //     st.insert(x);
        // }
        // ans.clear();
        // for(auto y:st){
        //     ans.push_back(y);
        // }
        // sort(ans.begin(),ans.end());
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
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
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