//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    // CONECPT -> PICK KIYA TOH BHI AAGE BADH JAYO
    // AUR PICK NAHI KIYA TOH BHI AAGYE BADH JAYO
    
    int recursive(int wt [],int val [],int n,int max_weight,int index)
    {
        if(max_weight<=0){
            return 0;
        }
        if(index==0)
        {
            
            if(wt[index]<=max_weight){
                return val[0];
            }
            else{
                return 0;
            }
        }
        int include=0;
        if(wt[index]<=max_weight)
        {
            // inclusion is possiblie
            include=val[index]+recursive(wt,val,n,max_weight-wt[index],index-1);
        }
        int exclude=recursive(wt,val,n,max_weight,index-1)+0;
        int ans=max(include,exclude);
        return ans;
    }
    
     int topdowndp(int wt [],int val [],int n,int max_weight,int index,vector<vector<int>>&dp)
    {
        if(index==0)
        {
            if(wt[index]<=max_weight)
            {
                return val[0];
            }
            else{
                return 0;
            }
        }
        if(dp[index][max_weight]!=-1){
            return dp[index][max_weight];
        }
        int include=0;
        if(wt[index]<=max_weight)
        {
            // inclusion is possiblie
            include=val[index]+topdowndp(wt,val,n,max_weight-wt[index],index-1,dp);
        }
        int exclude=topdowndp(wt,val,n,max_weight,index-1,dp)+0;
        int ans=max(include,exclude);
        dp[index][max_weight]=ans;
        return dp[index][max_weight];
    }
    
    int bottomupdp(int wt[],int val[],int n,int max_weight)
    {
        vector<vector<int>>dp(n,vector<int>(max_weight+1,0));
        
        // initialization for 0 index
        
        for(int w=wt[0];w<=max_weight;w++)
        {
            if(wt[0]<=max_weight)
            {
                dp[0][w]=val[0];
            }
            else{
                dp[0][w]=0;
            }
        }
        // int include=0;
        for(int index=1;index<n;index++)
        {
            for(int w=0;w<=max_weight;w++)
            {
                int include=0;
                  if(wt[index]<=w)
                  {
                      include=val[index]+dp[index-1][w-wt[index]];
                  }
                 int exclude=dp[index-1][w];
                 int ans=max(include,exclude);
                 dp[index][w]=ans;
            }
        }
        return dp[n-1][max_weight];
        
    }
    
     int space_optimization(int wt[],int val[],int n,int max_weight)
    {
        
        vector<int>prev(max_weight+1,0);
        
        vector<int>curr(max_weight+1,0);
        
        
        // initialization for 0 index
        
        for(int w=wt[0];w<=max_weight;w++)
        {
            if(wt[0]<=max_weight)
            {
                prev[w]=val[0];
            }
            else{
                prev[w]=0;
            }
        }
        // int include=0;
        for(int index=1;index<n;index++)
        {
            for(int w=0;w<=max_weight;w++)
            {
                int include=0;
                  if(wt[index]<=w)
                  {
                      include=val[index]+prev[w-wt[index]];
                  }
                 int exclude=prev[w];
                 int ans=max(include,exclude);
                 curr[w]=ans;
            }
            prev=curr;
        }
        return prev[max_weight];
        
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       
       // inclusion exclusion principle
       
    //   return recursive(wt,val,n,W,n-1);
    
    // vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
    // return topdowndp(wt,val,n,W,n-1,dp);
    
    // return bottomupdp(wt,val,n,W);
    
    
    return space_optimization(wt,val,n,W);
    
    
       
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
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends