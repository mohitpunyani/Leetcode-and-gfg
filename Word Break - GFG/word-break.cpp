//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

// IT'S A GOOD QUESTION  (leetcode par code hai)

//  DO DRY RUN FOR BETTER UNDERSTANDING

class Solution
{
    bool check(string temp,vector<string>&B)
    {
        for(int i=0;i<B.size();i++)
        {
            if(temp==B[i])
            {
                return true;
            }
        }
        return false;
    }
    bool solve(string A,vector<string>&B,int i,int a,int b)
    {
        if(i>=a)
        {
            return true;
        }
        for(int j=i;j<a;j++)
        {
            // LEARN SUBSTR FUNCTION (index,length)  IMP FUNCTION
            
            string temp=A.substr(i,j-i+1);
            if(check(temp,B) && solve(A,B,j+1,a,b))
            {
                // if both are true that means ki word find ho gaya
                
                return true;
                
            }
        }
        return false;
        
    }
    
    bool solve1(string A,set<string>&s,int i)
    {
        
        if(i>=A.size())
        {
            return true;
        }
        for(int j=i;j<A.size();j++)
        {
            string temp=A.substr(i,j-i+1);
            if(s.find(temp)!=s.end() && solve1(A,s,j+1))
            {
                return true;
            }
        }
        return false;
    }
    bool topdowndp(string A,set<string>&s,int i,vector<int>&dp)
    {
       if(i>=A.size())
        {
            return true;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        for(int j=i;j<A.size();j++)
        {
            string temp=A.substr(i,j-i+1);
            if(s.find(temp)!=s.end() && topdowndp(A,s,j+1,dp))
            {
                dp[i]=1;
                return dp[i];
            }
        }
        dp[i]=0;
        return dp[i]; 
    }
    bool bottomupdp(string A,set<string>&s)
    {
        
        int n=A.size();
        
        vector<bool>dp(n+1,false);
        
        dp[n]=true;
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                string temp=A.substr(i,j-i+1);
                if(s.find(temp)!=s.end() && dp[j+1])
                {
                    dp[i]=true;
                }
            }
            
        }
        return dp[0];
    }

public:
   
    int wordBreak(string A, vector<string> &B)
    {
        //code here
        
        // RECURSIVE SOLUTION
        
        
        // int a=A.size();
        // int b=B.size();
        // bool ans=solve(A,B,0,a,b);
        
        // return ans;
        
        // OPTIMIZED USING SET (this approach developed from approach 1)
        
        set<string>s;
        
        for(auto it:B)
        {
            s.insert(it);
        }
        
        // return solve1(A,s,0);
        
        // TOP DOWN DP (BECAUSE SUBPROBLEMS ARE OVERLAPPING)
        
        // 1d dp
        
        // vector<int>dp(A.size()+1,-1);
        
        // return topdowndp(A,s,0,dp);
        
        return bottomupdp(A,s);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends