//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	   int recursive(int n){
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        
        int temp=INT_MAX;
        for(int i=1;i<=sqrt(n);i++)
        {
            int square=i*i;
            int ans=recursive(n-square);
            temp=min(temp,1+ans);
        }
        return temp;
    }  
        int topdowndp(vector<int>&dp,int n){
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        
        if(dp[n]!=-1){
            return dp[n];
        }
        int temp=INT_MAX;
        for(int i=1;i<=sqrt(n);i++)
        {
            int square=i*i;
            int ans=topdowndp(dp,n-square);
            temp=min(temp,1+ans);
        }
        dp[n]=temp;
        return temp;
    }
    
    int bottomupdp(int n)
    {
           vector<int>dp(n+1,INT_MAX);
        
        if(n==0){
            return 0;
        }
        if(n==1 or n==2){
            return n;
        }
        dp[0]=0; // for 1 
        dp[1]=1;  // for 1
        dp[2]=2;   // for 2
        
        // store answer on the basis of one-based indexing 
        
        for(int i=3;i<=n;i++)
        {
            // for 3 to upto n;

            for(int j=1;j<=sqrt(n);j++)
            {
                int square=j*j;
                if(i-square>=0 && dp[i-square]!=INT_MAX)
                {
                    int ans=dp[i-square];
                    dp[i]=min(dp[i],1+ans);

                } 
                
            }
        }
        return dp[n];
    }
	int MinSquares(int n)
	{
	    // Code here
	   //   return recursive(n);
        
        //   vector<int>dp(n+1,-1);
        
        // return topdowndp(dp,n);
        
        // bottomupdp
        
        return bottomupdp(n);
        
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends