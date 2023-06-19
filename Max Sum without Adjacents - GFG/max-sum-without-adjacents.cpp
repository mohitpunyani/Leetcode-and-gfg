//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	
	// 1-d dp and inclusion exclusion principle
	
	int recursive(int *arr,int n,int index)
	{
	    if(index>=n){
	        return 0;
	    }
	    int include=arr[index]+recursive(arr,n,index+2);
	    int exclude=recursive(arr,n,index+1)+0;
	    int ans=max(include,exclude);
	    return ans;
	    
	}
	
	int topdowndp(int *arr,int n,int index,vector<int>&dp)
	{
	    if(index>=n){
	        return 0;
	    }
	    if(dp[index]!=-1)
	    {
	        return dp[index];
	    }
	    int include=arr[index]+topdowndp(arr,n,index+2,dp);
	    int exclude=topdowndp(arr,n,index+1,dp)+0;
	    int ans=max(include,exclude);
	    dp[index]=ans;
	    return dp[index];
	    
	}
	int bottomupdp(int *arr,int n)
	{
	    vector<int>dp(n,0);
	    dp[0]=arr[0];
	    dp[1]=max(arr[0],arr[1]);
	    for(int i=2;i<n;i++)
	    {
	        // for size 3
	       
	       int include=arr[i]+dp[i-2];
	       int exclude=0+dp[i-1];
	        dp[i]=max(include,exclude);
	    }
	    return dp[n-1];
	    
	}
	int space_optimization(int *arr,int n)
	{
	    if(n==1){
	        return arr[0];
	    }
	    if(n==2){
	        return max(arr[0],arr[1]);
	    }
	    int prev1=arr[0];
	    
	    int prev2=max(arr[0],arr[1]);
	    
	    for(int i=2;i<n;i++)
	    {
	        // start to get answers for size 3
	        int include=prev1+arr[i];
	        int exclude=prev2;
	        int ans=max(include,exclude);
	        prev1=prev2;
	        prev2=ans;
	        
	    }
	    return prev2;
	    
	}
	int findMaxSum(int *arr, int n) 
	{
	    // code here
	    
	    // like a house robber 
	    
	   // return recursive(arr,n,0);
	    
	   // vector<int>dp(n+1,-1);
	   // return topdowndp(arr,n,0,dp);
	   
	   //return bottomupdp(arr,n);
	   
	   return space_optimization(arr,n);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends