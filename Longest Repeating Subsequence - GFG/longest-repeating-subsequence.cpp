//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	
	
	// variation of lcs
	int recursive(int x,int y,string s1,string s2,int i,int j)
    {
        if(i>=x)
        {
            return 0;
            
        }
        if(j>=y)
        {
            return 0;
        }
        int ans=0;
        if(s1[i]==s2[j] && i!=j)
        {
            ans+=1+recursive(x,y,s1,s2,i+1,j+1);
            
        }
        
        else{
            // not equal or character not match
            ans+=max(recursive(x,y,s1,s2,i,j+1),recursive(x,y,s1,s2,i+1,j));
        }
        return ans;
    }
    
     int topdowndp(int x,int y,string s1,string s2,int i,int j,vector<vector<int>>&dp)
    {
        if(i>=x)
        {
            return 0;
            
        }
        if(j>=y)
        {
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(s1[i]==s2[j] && i!=j)
        {
            ans+=1+topdowndp(x,y,s1,s2,i+1,j+1,dp);
            
        }
        
        else{
            // not equal or character not match
            ans+=max(topdowndp(x,y,s1,s2,i,j+1,dp),topdowndp(x,y,s1,s2,i+1,j,dp));
        }
        dp[i][j]=ans;
        return dp[i][j];
    }
    
    int bottomupdp(int x,int y,string s1,string s2)
    {
        vector<vector<int>>dp(x+1,vector<int>(y+1,0));
        for(int i=x-1;i>=0;i--)
        {
            for(int j=y-1;j>=0;j--)
            {
                int ans=0;
                if(s1[i]==s2[j] && i!=j){
                    ans=1+dp[i+1][j+1];
                }
                else{
                    ans=max(dp[i][j+1],dp[i+1][j]);
                }
                dp[i][j]=ans;
            }
    
        }
        
        return dp[0][0];
        
    }
    
     int space_optimization(int x,int y,string s1,string s2)
    {
        vector<int>curr(y+1,0);
        
        vector<int>next(y+1,0);
        
        for(int i=x-1;i>=0;i--)
        {
            for(int j=y-1;j>=0;j--)
            {
                int ans=0;
                if(s1[i]==s2[j] && i!=j){
                    ans=1+next[j+1];
                }
                else{
                    ans=max(curr[j+1],next[j]);
                }
                curr[j]=ans;
            }
            next=curr;
    
        }
        
        return next[0];
        
    }
		int LongestRepeatingSubsequence(string str)
		{
		    // Code here
		    
		    string s1=str;
		    
		    string s2=str;
		    
		    int x=str.size();
		    
		    int y=str.size();
		    
		  //  return recursive(x,y,s1,s2,0,0);
		  
		  //vector<vector<int>>dp(x+1,vector<int>(y+1,-1));
		  //return topdowndp(x,y,s1,s2,0,0,dp);
		  
		  //return bottomupdp(x,y,s1,s2);
		  
		  return space_optimization(x,y,s1,s2);
		    
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
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends