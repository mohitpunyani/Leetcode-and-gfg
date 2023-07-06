//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

// CATCH -> MAXIMUM NO OF PARTITIONS FOR SUBSTRING TO BE PALINDROME IS (STR.LENGTH -1 )

// GOOD QUESTION  (easy question )

// find minimum cuts needed for palindromic substring

// CATCH -> we have a choices to do partition at every characters

// SO THINK RECURSION

bool is_palindrome(string s){
    
    int low=0;
    int high=s.size()-1;
    while(low<=high)
    {
        if(s[low]!=s[high]){
            return false;
        }
        low++;
        high--;
    }
    return true;
}

int dfs(string str,int i)
{
    if(i>=str.size())
    {
        return -1;
    }
    int ans=INT_MAX;
    
    for(int j=i;j<str.size();j++)
    {
        string temp=str.substr(i,j-i+1);
        
        if(is_palindrome(temp))
        {
            int temp=1+dfs(str,j+1);
            ans=min(ans,temp);
            
        }
    }
    return ans;
}
int topdowndp(string str,int i,vector<int>dp)
{
    if(i>=str.size())
    {
        return -1;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int ans=INT_MAX;
    
    for(int j=i;j<str.size();j++)
    {
        string temp=str.substr(i,j-i+1);
        
        if(is_palindrome(temp))
        {
            int temp=1+topdowndp(str,j+1,dp);
            ans=min(ans,temp);
            
        }
    }
    dp[i]=ans;
    return dp[i];
}
int bottomupdp(string str)
{
    
    vector<int>dp(str.size()+1,0);
    
    for(int i=str.size()-1;i>=0;i--)
    {
        int ans=INT_MAX;
        
        for(int j=i;j<str.size();j++)
        {
            string temp=str.substr(i,j-i+1);
            
            if(is_palindrome(temp))
            {
                int temp=1+dp[j+1];
                ans=min(ans,temp);
            }
        }
        dp[i]=ans;
    }
    
    return dp[0]-1;
}
    int palindromicPartition(string str)
    {
        // code here
        
        // DFS ON STRING (IMP)  or RECURSIVE 
        
        
        // return dfs(str,0);
        
        // topdowndp
        
        if(is_palindrome(str))
        {
            return 0;
        }
        
        // vector<int>dp(str.size()+1,-1);
        // return topdowndp(str,0,dp);
        
        // bottomupdp
        
        //  1D DP 
        
        return bottomupdp(str);
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends