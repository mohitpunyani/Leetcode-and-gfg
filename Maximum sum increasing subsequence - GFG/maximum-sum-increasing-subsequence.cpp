//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	
	  int recursive(int n,int a[],int curr,int prev)
    {
        if(curr>=n)
        {
            return 0;
        }
        int take=0;
        if(prev==-1 || a[curr]>a[prev])
        {
            take=a[curr]+recursive(n,a,curr+1,curr);
            
        }
        int not_take=recursive(n,a,curr+1,prev);
        
        int ans=max(take,not_take);
        
        return ans;
        
    }
    
    int topdowndp(int n,int a[],int curr,int prev,vector<vector<int>>&dp)
    {
        if(curr>=n)
        {
            return 0;
        }
        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }
        int take=0;
        if(prev==-1 || a[curr]>a[prev])
        {
            take=a[curr]+topdowndp(n,a,curr+1,curr,dp);
            
        }
        
        int not_take=topdowndp(n,a,curr+1,prev,dp);
        
        int ans=max(take,not_take);
        
        dp[curr][prev+1]=ans;
        
        return dp[curr][prev+1];
        
    }
    
    int bottomupdp(int n,int a[]){
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        // PAHALE CURR KA LOOP CHALEGA
        
        for(int curr=n-1;curr>=0;curr--)
        {
            for(int prev=curr-1;prev>=-1;prev--)
            {
                int take=0;
                if(prev==-1 || a[curr]>a[prev])
                {
                    take=a[curr]+dp[curr+1][curr+1];
                }
                int not_take=dp[curr+1][prev+1];
                int ans=max(take,not_take);
                dp[curr][prev+1]=ans;
            }
        }
        return dp[0][0];
    }

     int space_optimization(int n,int a[]){
        
        vector<int>curr_row(n+1,0);
        
        vector<int>next_row(n+1,0);
        
        // PAHALE CURR KA LOOP CHALEGA
        
        for(int curr=n-1;curr>=0;curr--)
        {
            for(int prev=curr-1;prev>=-1;prev--)
            {
                int take=0;
                if(prev==-1 || a[curr]>a[prev])
                {
                    take=a[curr]+next_row[curr+1];
                }
                int not_take=next_row[prev+1];
                int ans=max(take,not_take);
                curr_row[prev+1]=ans;
            }
            next_row=curr_row;
        }
        return next_row[0];
    }
    
     int more_space_optimization(int n,int a[]){
        
        vector<int>curr_row(n+1,0);
        
        // PAHALE CURR KA LOOP CHALEGA
        
        for(int curr=n-1;curr>=0;curr--)
        {
            for(int prev=curr-1;prev>=-1;prev--)
            {
                int take=0;
                if(prev==-1 || a[curr]>a[prev])
                {
                    take=a[curr]+curr_row[curr+1];
                }
                int not_take=curr_row[prev+1];
                int ans=max(take,not_take);
                curr_row[prev+1]=ans;
            }
        }
        return curr_row[0];
    }
   
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    
	   //return recursive(n,arr,0,-1);
    
    
    // vector<vector<int>>dp(n,vector<int>(n+1,-1));
    // return topdowndp(n,arr,0,-1,dp);
    
    // return bottomupdp(n,arr);
   
    // return space_optimization(n,arr);
    
    return more_space_optimization(n,arr);
   
	    
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends