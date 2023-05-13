//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 

NOTE
 void find(int i,int target,vector<int> &A, vector<vector<int>>&ans,vector<int>&v)

     {

         if(i==A.size())

         {

             if(target==0)

             {

                ans.push_back(v); 

             }

             return;

         }

         

         if(A[i]<=target)

         {

            v.push_back(A[i]);

            find(i,target-A[i],A,ans,v);

            v.pop_back();

         }

         

         find(i+1,target,A,ans,v);

     }
    vector<vector<int> > combinationSum(vector<int> &A, int B) 
    {
        // Your code here 
            vector<vector<int>>ans;

       vector<int>v;

       sort(A.begin(),A.end());

       A.erase(unique(A.begin(),A.end()),A.end());

       find(0,B,A,ans,v);

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