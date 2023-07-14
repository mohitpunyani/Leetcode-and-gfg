//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
  
    bool is_palindrome(string str)
    {
        int low=0;
        int high=str.size()-1;
        while(low<=high)
        {
            if(str[low]!=str[high])
            {
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
    
    // LPS VARIATION
    
    // ans = string_length - LPS
    
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
        int ans=INT_MIN;
        if(s1[i]==s2[j])
        {
            ans=1+recursive(x,y,s1,s2,i+1,j+1);
            
        }
        else{
            // not equal or character not match
            int opt1=recursive(x,y,s1,s2,i,j+1);
            
            int opt2=recursive(x,y,s1,s2,i+1,j);
            
            int temp=max(opt1,opt2);
            ans=max(temp,ans);
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
        int ans=INT_MIN;
        if(s1[i]==s2[j])
        {
            ans=1+topdowndp(x,y,s1,s2,i+1,j+1,dp);
            
        }
        
        else{
            // not equal or character not match
            int opt1=topdowndp(x,y,s1,s2,i,j+1,dp);
            int opt2=topdowndp(x,y,s1,s2,i+1,j,dp);
            
            int temp=max(opt1,opt2);
            
            ans=max(temp,ans);
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
                int ans=INT_MIN;
                if(s1[i]==s2[j]){
                    ans=1+dp[i+1][j+1];
                }
                else{
                    int opt1=dp[i][j+1];
                    int opt2=dp[i+1][j];
                    int temp=max(opt1,opt2);
                    ans=max(temp,ans);
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
                int ans=INT_MIN;
                if(s1[i]==s2[j]){
                    ans=1+next[j+1];
                }
                else{
                    int opt1=curr[j+1];
                    int opt2=next[j];
                    
                    int temp=max(opt1,opt2);
                    
                    ans=max(ans,temp);
                }
                curr[j]=ans;
            }
            next=curr;
    
        }
        
        return next[0];
    }
    int countMin(string str){
        
    //complete the function here
    
      if(is_palindrome(str))
      {
          return 0;
      }
        string s1=str;
        reverse(str.begin(),str.end());
        string s2=str;
        int x=s1.size();
        
        int y=s2.size();
        
        
        // return x-recursive(x,y,s1,s2,0,0);
        
        // vector<vector<int>>dp(x,vector<int>(y,-1));
        // return x-topdowndp(x,y,s1,s2,0,0,dp);
        
        // return x-bottomupdp(x,y,s1,s2);
        
        return x-space_optimization(x,y,s1,s2);
        
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends