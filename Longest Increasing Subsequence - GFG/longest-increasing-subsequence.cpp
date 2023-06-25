//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    
    //Function to find length of longest increasing subsequence.
    
    int recursive(int n,int a[],int curr,int prev)
    {
        if(curr>=n)
        {
            return 0;
        }
        int take=0;
        if(prev==-1 || a[curr]>a[prev])
        {
            take=1+recursive(n,a,curr+1,curr);
            
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
            take=1+topdowndp(n,a,curr+1,curr,dp);
            
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
                    take=1+dp[curr+1][curr+1];
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
                    take=1+next_row[curr+1];
                }
                int not_take=next_row[prev+1];
                int ans=max(take,not_take);
                curr_row[prev+1]=ans;
            }
            next_row=curr_row;
        }
        return next_row[0];
    }
    
    // DP WITH BINARY SEARCH (love babbar)
    
    int dp_with_binary_search(int n,int a[])
    {
        vector<int>ans;
        ans.push_back(a[0]);
        
        for(int i=1;i<n;i++)
        {
            if(a[i]>ans.back()){
                ans.push_back(a[i]);
            }
            else{
                
                int index=lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
                
                ans[index]=a[i];
            }
            
        }
        return ans.size();
        
    }
    int longestSubsequence(int n, int a[])
    {
       // your code here
       
    //   return recursive(n,a,0,-1);
    
    
    // vector<vector<int>>dp(n,vector<int>(n+1,-1));
    // return topdowndp(n,a,0,-1,dp);
    
    // return bottomupdp(n,a);
   
    // return space_optimization(n,a);
    
    return dp_with_binary_search(n,a);
    
    
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends