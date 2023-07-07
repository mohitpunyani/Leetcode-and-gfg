//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};


// } Driver Code Ends
/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

class Solution{
public:

// we have a choices so write recursive code (easy question, done in first attempt)
    
    // IMP OR V. IMP -> CUSTOM OPERATOR TRUE PAR AAGE BADH JAYEGA AUR FALSE PAR SWAP KAREGA.
    
    /*You are required to complete this method*/
    
    static bool comp(pair<int,int>a,pair<int,int>b)
  {
    return a.second<b.second;
   }
    // LIS VARIATION OR LOGIC
    
    int recursive(vector<pair<int,int>>&v,int n,int prev,int index)
    {
        
        // based on inclusion exclusion principle
        
        if(index>=n)
        {
            return 0;
        }
        
        int take=0;
        if(prev==-1  or v[prev].second<v[index].first)
        {
            take=1+recursive(v,n,index,index+1);
        }
        int not_take=0+recursive(v,n,prev,index+1);
        int ans=max(take,not_take);
        return ans;
    }  
    int topdowndp(vector<pair<int,int>>&v,int n,int prev,int index,vector<vector<int>>&dp)
    {
        
        // based on inclusion exclusion principle
        
        if(index>=n)
        {
            return 0;
        }
        
        if(dp[index][prev+1]!=-1)
        {
            return dp[index][prev+1];
        }
        int take=0;
        if(prev==-1  or v[prev].second<v[index].first)
        {
            take=1+topdowndp(v,n,index,index+1,dp);
        }
        int not_take=0+topdowndp(v,n,prev,index+1,dp);
        int ans=max(take,not_take);
        dp[index][prev+1]=ans;
        return dp[index][prev+1];
    }
    int bottomupdp(vector<pair<int,int>>v,int n)
    {
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int index=n-1;index>=0;index--)
        {
            for(int prev=index-1;prev>=-1;prev--)
            {
                int take=0;
                if(prev==-1  or v[prev].second<v[index].first)
                {
                    take=1+dp[index+1][index+1];
                }
                int not_take=dp[index+1][prev+1];
                int ans=max(take,not_take);
                dp[index][prev+1]=ans;
          
            }
        }
        
        return dp[0][0];
        
    }
    
    int maxChainLen(struct val p[],int n)
    {
        //Your code here
        
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({p[i].first,p[i].second});
        }
    
        // sort on the basis of second value
        // n=v.size();
        sort(v.begin(),v.end(),comp);
        
        // RECURSIVE
        
        // return recursive(v,n,-1,0);
        
        // TOPDOWNDP
        
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // return topdowndp(v,n,-1,0,dp);
        
        // BOTTOMUPDP
        
        // return bottomupdp(v,n);
        
        // GREEDY APPROACH 
        
        int ans=1;
        int prev=v[0].second;
        for(int i=1;i<n;i++)
        {
            if(v[i].first>prev)
            {
                ans++;
                prev=v[i].second;
                
            }
            else{
                continue;
            }
        }
        return ans;
        
        
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		Solution ob;
		cout<<ob.maxChainLen(p,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends