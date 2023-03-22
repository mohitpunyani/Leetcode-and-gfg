//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:

vector<vector<int>> ans;
vector<int>v;
    void help(vector<int>& a ,int sum , int s , int e){
        if(sum < 0){
            return;
        }
        if(sum == 0){
            ans.push_back(v);
            return;
        }
        for(int i = s ; i<e; i++){
            v.push_back(a[i]);
            help(a , sum-a[i]  , i , e);
            v.pop_back();
        }
        // return ;
    }
    vector<vector<int> > combinationSum(vector<int> &a, int x) {
        // Your code here
        sort(a.begin() ,a.end());
        a.resize(unique(a.begin() , a.end())-a.begin());
        int n = a.size();
        help(a , x ,0 , n );
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