//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	

// LOGICAL MATHS (thinking must be good)

// using map

// CATCH -> agar sum divisible by k hai toh remainder zero hoga 

// we know that divisible = divident * quotient + remainder 


// code with alisha

// CATCH -> WHEN EVER TWO SUBARRAYS HAVE SAME REMAINDER THAN REMAINDER IS CANCEL OUT 
// AND WE GET THE MULTIPLES OF K


	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    
	    int ans=0;
	    
	    int sum=0;
	    
	    unordered_map<int,int>mp;
	    
	    mp[0]=-1;
	    for(int i=0;i<n;i++)
	    {
	        sum=sum+arr[i];
	        int rem=sum%k;
	        
	        if(rem<0){
	            rem=rem+k;
	        }
	        if(mp.find(rem)!=mp.end())
	        {
	            ans=max(ans,i-mp[rem]);
	            
	        }
	        else{
	            mp[rem]=i;
	        }
	        
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends