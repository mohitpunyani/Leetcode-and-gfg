//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	
	//  IT'S A GOOD QUESTION (beautiful)
	
	// CATCH - > YOU CAN'T TAKE OR DECODE THREE NUMBERS

     // OR YOU TAKE NUMBER WHICH IS LESS THAN 26
     
     // FIBONACCI VARIATION 
     
     
     int MOD=1000000007;
     int recursive(string s,int idx,int n)
    {
        
        
        if(idx < n && s[idx] == '0')
        
        return 0;
        if(idx >= n)
            return 1;
        
        int ways = 0;
        
        // Pick single
        
        int one=0;
        
        int two=0;
        
        if(s[idx]!=0)
           one = recursive(s, idx+1, n);
            
        // Pick couple
        if(idx+1 < n && ((s[idx] == '1' && s[idx+1] <= '9') || (s[idx]=='2' && s[idx+1] < '7')))
           two = recursive(s, idx+2, n);
        
        ways=one+two;  
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
        
        int one=0;
        
        int two=0;
        
        if(s[idx] != '0')
        one= topdowndp(s, idx+1, n,dp);
            
        // Pick couple (IMP CONDITION)
        
        if(idx+1 < n && ((s[idx] == '1' && s[idx+1] <= '9') || (s[idx]=='2' && s[idx+1] < '7')))
          two = topdowndp(s, idx+2, n,dp);
         
        ways=one+two;
        dp[idx]=ways%MOD;  
        return dp[idx];
     }
     
     int bottomupdp(string s,int n){
         
         vector<int>dp(n+2,0);
         
         dp[n]=1;
         
         int ways=0;
         
         for(int i=0;i<n;i++){
             if(s[i]=='0')
             {
                 dp[i]=0; 
             }
         }
          
            for (int i = n - 1; i >= 0; --i)
            {
                // IMP CATCH -> we can't pick one digit if we found a zero
                
                if (s[i] != '0') 
                {
                  dp[i]=(dp[i]+dp[i + 1])%MOD;
                }
                
                // but we can pick two digits including zero  but less than 26
                
                
                if (i+1 < n && ((s[i] == '1' && s[i+1]<='9') || (s[i] == '2' && s[i + 1] <= '6'))) {
                  dp[i]= (dp[i]+dp[i + 2])%MOD;
                }
            }
          return dp[0]%MOD;
       
         
     }
		int CountWays(string str)
		{
		    // Code here
		    
		    // DFS ON STRING OR RECURSIVE
		    
		    int n=str.size();
		    
		  //  return recursive(str,0,n);
		    
		  //  vector<int>dp(n+1,-1);
		  //  return  topdowndp(str,0,n,dp);
		    
		    return bottomupdp(str,n);
		    
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