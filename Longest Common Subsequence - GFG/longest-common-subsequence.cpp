//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

//  IQ MUST BE GOOD
class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    
    // SUBARRAY -> CONTINUOUS (PRIORITY CONDITION)
    // SUBSEQUENCE -> ORDER (PRIORITY CONDITION)
    
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
        if(s1[i]==s2[j])
        {
            ans=1+recursive(x,y,s1,s2,i+1,j+1);
            
        }
        
        else{
            // not equal or character not match
            ans=max(recursive(x,y,s1,s2,i,j+1),recursive(x,y,s1,s2,i+1,j));
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
        if(s1[i]==s2[j])
        {
            ans=1+topdowndp(x,y,s1,s2,i+1,j+1,dp);
            
        }
        
        else{
            // not equal or character not match
            ans=max(topdowndp(x,y,s1,s2,i,j+1,dp),topdowndp(x,y,s1,s2,i+1,j,dp));
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
                if(s1[i]==s2[j]){
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
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        
        // return recursive(x,y,s1,s2,0,0);
        
        // vector<vector<int>>dp(x,vector<int>(y,-1));
        // return topdowndp(x,y,s1,s2,0,0,dp);
        
        return bottomupdp(x,y,s1,s2);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends