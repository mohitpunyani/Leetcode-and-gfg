//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

   bool recursive(vector<int>&arr,int sum,int n,int index)
   {
       if(sum==0){
           return true;
       }
       if(sum<0){
           return false;
       }
       if(index==0)
       {
           if(sum==arr[0])
           {
               return true;
           }
           else{
               return false;
           }
           
           
       }
       
       bool include;
       if(arr[index]<=sum){
          include=recursive(arr,sum-arr[index],n,index-1);
       }
       bool exclude=recursive(arr,sum,n,index-1);
       bool ans=include or exclude;
       return ans;
   }
    bool topdowndp(vector<int>&arr,int sum,int n,int index,vector<vector<int>>&dp)
   {
      if(sum==0)
       {
           return true;
       }
      if(sum<0){
          return false;
      }
      if(index==0)
       {
           if(sum==arr[0])
           {
               return true;
           }
           else{
               return false;
           }
           
           
       }
       if(dp[index][sum]!=-1)
       {
           return dp[index][sum];
       }
    
       bool include=false;
       if(arr[index]<=sum){
          include=topdowndp(arr,sum-arr[index],n,index-1,dp);
       }
       bool exclude=topdowndp(arr,sum,n,index-1,dp);
       bool ans=include || exclude;
       dp[index][sum]=ans;
       return dp[index][sum];
   }
   
   bool bottomupdp(vector<int>&arr,int sum,int n)
   {
       vector<vector<bool>>dp(n,vector<bool>(sum+1,0));
       
       // initialization
       
       for(int i=0;i<n;i++){
           dp[i][0]=true;
       }
       
       for(int target=0;target<=sum;target++)
       {
           if(target==arr[0])
           {
                dp[0][target]=true;
           }
           else{
            dp[0][target]=false;
           }
       }
       for(int index=1;index<n;index++){
           for(int s=1;s<=sum;s++)
           {
               bool include=false;
               if(arr[index]<=s){
                   include=dp[index-1][s-arr[index]];
               }
               bool exclude=dp[index-1][s];
               bool ans=include or exclude;
               dp[index][s]=ans;
           }
           
       }
       return dp[n-1][sum];
   }
    bool space_optimization(vector<int>&arr,int sum,int n){
        
       vector<bool>prev(sum+1,0);
       
       vector<bool>curr(sum+1,0);
       
       for(int i=0;i<n;i++){
           curr[0]=true;
       }
       
       for(int target=0;target<=sum;target++)
       {
           if(target==arr[0])
           {
                prev[target]=true;
           }
           else{
                prev[target]=false;
           }
       }
       for(int index=1;index<n;index++){
           for(int s=1;s<=sum;s++)
           {
               bool include=false;
               if(arr[index]<=s){
                   include=prev[s-arr[index]];
               }
               bool exclude=prev[s];
               bool ans=include or exclude;
               curr[s]=ans;
           }
           
           prev=curr;
       }
       return prev[sum];
   }
    bool isSubsetSum(vector<int>arr, int sum)
    {
        // code here
        
        int n=arr.size();
        // return recursive(arr,sum,n,n-1
        
        // vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        // return topdowndp(arr,sum,n,n-1,dp);
        
        // return bottomupdp(arr,sum,n);
        
        
        return space_optimization(arr,sum,n);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends