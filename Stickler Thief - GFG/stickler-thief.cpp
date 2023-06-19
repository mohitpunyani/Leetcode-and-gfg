//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
       int recursive(int nums[],int index,int n)
    {
        if(index>=n)
        {
            return 0;
        }
        int include=nums[index]+recursive(nums,index+2,n);
        int exclude=recursive(nums,index+1,n)+0;
        int ans=max(include,exclude);
        return ans;
        
    }
     int topdowndp(vector<int>&dp,int nums [],int index,int n)
    {
        if(index>=n)
        {
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int include=nums[index]+topdowndp(dp,nums,index+2,n);
        int exclude=topdowndp(dp,nums,index+1,n)+0;
        int ans=max(include,exclude);
        dp[index]=ans;
        return dp[index];
    }
    
     int bottomupdp(int nums[],int n)
    {
    
        
        if(n==1){
            return nums[0];
        }
        vector<int>dp(n,0);
        
        dp[0]=nums[0];
        
        dp[1]=max(nums[0],nums[1]);
        
        for(int i=2;i<n;i++)
        {
            // for size 3 
            
            int include=dp[i-2]+nums[i];
            
            int exclude=dp[i-1]+0;
            
            dp[i]=max(include,exclude);
        }
        return dp[n-1];
    }
        int space_optimization(int nums[],int n)
    {
        
         if(n==1){
            return nums[0];
        }
        int prev1=nums[0];
        
        int prev2=max(nums[0],nums[1]);
        
        for(int i=2;i<n;i++){
            
            
            int include=prev1+nums[i];
            
            int exclude=prev2+0;
            int ans=max(include,exclude);
            
            prev1=prev2;
            
            prev2=ans;
        }
        return prev2;
        
    }
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        // return recursive(arr,0,n);
        
        // topdowndp
        // vector<int>dp(n+1,-1);
        // return topdowndp(dp,arr,0,n);
        
           // bottomupdp
        
        // return bottomupdp(arr,n);
        
        return space_optimization(arr,n);
        
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends