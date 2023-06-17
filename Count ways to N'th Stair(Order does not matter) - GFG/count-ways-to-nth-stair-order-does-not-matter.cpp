//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	int recursive(int n){
	    if(n==0 or n==1){
	        return 1;
	    }
	    int ans=1+min(recursive(n-1),recursive(n-2));
	    return ans;
	}
	
	int topdowndp(vector<int>&dp,int n){
	    if(n==0 or n==1){
	        return 1;
	    }
	    if(dp[n]!=-1){
	        return dp[n];
	    }
	    dp[n]=1+min(topdowndp(dp,n-1),topdowndp(dp,n-2));
	    return dp[n];
	}
	int bottomupdp(int n)
	{
	    vector<int>dp(n+1,0);
	    
	    dp[0]=1;
	    dp[1]=1;
	    dp[2]=2;
	    for(int i=3;i<=n;i++){
	        dp[i]=1+min(dp[i-1],dp[i-2]);
	    }
	    return dp[n];
	}
	int space_optimization(int n){
	    
	    if(n==1){
	        return 1;
	    }
	    if(n==2){
	        return 2;
	    }
	    int prev1=1;
	    int prev2=2;
	    
	    for(int i=3;i<=n;i++)
	    {
	        int curr=1+min(prev1,prev2);
	        
	        prev1=prev2;
	        
	        prev2=curr;
	    }
	    return prev2;
	}
		int nthStair(int n)
		{
		    //  Code here
		    
		    // RECURSIVE
		    
		  //  return recursive(n);
		    
		    // TOPDOWN DP
		    
		  //  vector<int>dp(n+1,-1);
		  //  return topdowndp(dp,n);
		  
		  
		  // BOTTOMUP DP 
		  
		  //return bottomupdp(n);
		  
		  
		  // SPACE OPTIMIZATION 
		  
		  return space_optimization(n);
		    
		    
		    
		    
		    
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
		int ans  = ob.nthStair(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends