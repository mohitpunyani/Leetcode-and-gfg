//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	
		  int recursive(int coins[],int amount,int size)
    {
        if(amount==0){
            return 0;
        }
        if(amount<0){
            // IT DENOTES THAT ANSWER IS -1
            return INT_MAX;
        }
        int mini=INT_MAX;
        for(int i=0;i<size;i++)
        {
            int ans=recursive(coins,amount-coins[i],size);
            if(ans!=INT_MAX)
            {
                mini=min(mini,1+ans);
            }
            else{
                continue;
            }
    
        }
        return mini;
        
    }
      int topdowndp(vector<int>&dp,int coins[],int amount,int size)
    {
        // recursive calls overlap toh ho rahi hai
        if(amount==0){
            return 0;
        }
        
        if(amount<0){
            // IT DENOTES THAT ANSWER IS -1
            return INT_MAX;
        }
        if(dp[amount]!=-1){
            return dp[amount];
        }
        int mini=INT_MAX;
        for(int i=0;i<size;i++)
        {
            int ans=topdowndp(dp,coins,amount-coins[i],size);
            if(ans!=INT_MAX)
            {
                mini=min(mini,1+ans);
            }
            else{
                continue;
            }
    
        }
        dp[amount]=mini;
        return dp[amount];
        
    }
    
         int bottomupdp(int coins[],int amount,int size)
    {
        vector<int>dp(amount+1,INT_MAX);
        dp[0]=0; // ans for zero amount
        
        for(int j=1;j<=amount;j++)
        {
            for(int i=0;i<size;i++)
            {
                // build answer
                if(j-coins[i]>=0 && dp[j-coins[i]]!=INT_MAX)
                {
                     int ans=dp[j-coins[i]];
                     dp[j]=min(dp[j],1+ans);
                     
                }
                else{
                    continue;
                }
                
                
            }
            
        }
        if(dp[amount]==INT_MAX){
            return -1;
        }
        return dp[amount];
    }
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    
	   // int size=M;
	   // int ans=recursive(coins,V,size);
	   // ans=ans==INT_MAX?-1:ans;
	   // return ans;
	   
	   // TOP DOWN DP
	    
	   // int amount=V;
	   // vector<int>dp(amount+1,-1);
    //     int ans=topdowndp(dp,coins,amount,M);
    //     if(ans==INT_MAX){
    //         return -1;
    //     }
    //     return ans;
        
        
        // BOTTOMUP DP 
         int amount=V;
         return bottomupdp(coins,amount,M);
        
        
	    
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends