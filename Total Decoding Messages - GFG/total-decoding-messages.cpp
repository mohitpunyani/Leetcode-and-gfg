//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	
	//  IT'S A GOOD QUESTION 
	
	// CATCH - > YOU CAN'T TAKE OR DECODE THREE NUMBERS

     // OR YOU TAKE NUMBER WHICH IS LESS THAN 26
     
     int MOD=1000000007;
     int recursive(string s,int idx,int n)
    {
        
        
        if(idx < n && s[idx] == '0')
        
        return 0;
        if(idx >= n)
            return 1;
        
        int ways = 0;
        
        // Pick single
        
        ways += recursive(s, idx+1, n);
            
        // Pick couple
        if(idx+1 < n && ((s[idx] == '1' && s[idx+1] <= '9') || (s[idx]=='2' && s[idx+1] < '7')))
           ways += recursive(s, idx+2, n);
           
        return ways%MOD;
     }
     
     int topdowndp(string s,int idx,int n,vector<int>&dp)
    {
        
        
        if(idx < n && s[idx] == '0') return 0;
        if(idx >= n)
            return 1;
        
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int ways = 0;
        
        // Pick single
        
        // if(s[idx] != '0')
        ways += topdowndp(s, idx+1, n,dp);
            
        // Pick couple
        if(idx+1 < n && ((s[idx] == '1' && s[idx+1] <= '9') || (s[idx]=='2' && s[idx+1] < '7')))
          ways += topdowndp(s, idx+2, n,dp);
         
        dp[idx]=ways%MOD;  
        return dp[idx];
     }
		int CountWays(string str)
		{
		    // Code here
		    
		    // DFS ON STRING OR RECURSIVE
		    
		    int n=str.size();
		    
		  //  return recursive(str,0,n);
		    
		    vector<int>dp(n+1,-1);
		    
		    return  topdowndp(str,0,n,dp);
		    
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends