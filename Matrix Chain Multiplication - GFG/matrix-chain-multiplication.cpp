//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
 // STRIVER
 
//  PARTITION DP

// MCM

int recursive(int i,int j,int arr[])
{
    if(i==j){
        return 0;
    }
    int mn=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int steps=arr[i-1]*arr[k]*arr[j]+recursive(i,k,arr)+recursive(k+1,j,arr);
        mn=min(mn,steps);
    }
    return mn;
}
int topdowndp(int i,int j,int arr[],vector<vector<int>>&dp)
{
    if(i==j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int mn=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int steps=arr[i-1]*arr[k]*arr[j]+topdowndp(i,k,arr,dp)+topdowndp(k+1,j,arr,dp);
        mn=min(mn,steps);
        
    }
    dp[i][j]=mn;
    return dp[i][j];
}

int bottomup
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        
        // return recursive(1,N-1,arr);   
        
        // TOPDOWNDP
        
        vector<vector<int>>dp(N+1,vector<int>(N+1,-1));
        return topdowndp(1,N-1,arr,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends