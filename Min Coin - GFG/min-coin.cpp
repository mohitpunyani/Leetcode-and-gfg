//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	  int recursive(vector<int>&coins,int amount)
    {
        if(amount==0){
            return 0;
        }
        if(amount<0){
            // IT DENOTES THAT ANSWER IS -1
            return INT_MAX;
        }
        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++)
        {
            int ans=recursive(coins,amount-coins[i]);
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
    
    
     
    int topdowndp(vector<int>&dp,vector<int>&coins,int amount)
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
        for(int i=0;i<coins.size();i++)
        {
            int ans=topdowndp(dp,coins,amount-coins[i]);
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
	int MinCoin(vector<int>nums, int amount)
	{
	    // Code here
	   // int ans=recursive(nums,amount);
	   // ans=ans==INT_MAX?-1:ans;
	   // return ans;
	    
	    
	   //TOPDOWNDP 
        
        vector<int>dp(amount+1,-1);
        
        int ans=topdowndp(dp,nums,amount);
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
        
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends