//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    
    bool recursive(string A,string B,string C,int i,int j,int k)
    {
        if(A.size()+B.size()!=C.size()){
            return false;
        }
        // if(k==C.size() && (i<A.size() or j<B.size())){
        //     return false;
        // }
        if(i==A.size() && j==B.size() && k==C.size())
        {
            return true;
        }
        bool a=false;
        bool b=false;
        if(A[i]==C[k])
        {
            a=recursive(A,B,C,i+1,j,k+1);
        }
        if(B[j]==C[k]){
            b=recursive(A,B,C,i,j+1,k+1);
        }
        
        return a or b;
    } 
    
    bool topdowndp(string A,string B,string C,int i,int j,int k,vector<vector<int>>&dp)
    {
        if(A.size()+B.size()!=C.size()){
            return false;
        }
       
        if(i>=A.size() && j>=B.size() && k>=C.size())
        {
            return true;
        }
        //  if(k==C.size() && (i<A.size() or j<B.size())){
        //     return false;
        // }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        bool a=false;
        bool b=false;
        if(i!=A.size())
        {
            if(A[i]==C[k])
            {
                a=topdowndp(A,B,C,i+1,j,k+1,dp);
            }
        }
        if(j!=B.size()){
            
            if(B[j]==C[k]){
                b=topdowndp(A,B,C,i,j+1,k+1,dp);
            }
        }
        
        dp[i][j]=a or b;
        return dp[i][j];
    }
    bool isInterleave(string A, string B, string C) 
    {
        //Your code here
        
        // return recursive(A,B,C,0,0,0);
        
        vector<vector<int>>dp(A.size()+1,vector<int>(B.size()+1,-1));
        return topdowndp(A,B,C,0,0,0,dp);
        
    }

};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends