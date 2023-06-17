//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
int mod=1000000007;
    long long int fibSum(long long int N)
    {
        if(N==0 or N==1 or N==2){
            return N;
        }
        //code here
        long long int a=0;
        long long int b=1;
        long long int sum=1;
        
        for(int i=2;i<=N;i++)
        {
            long long int curr=(a+b)%mod;
            
            sum=(sum+curr)%mod;
            
            a=b;
            b=curr;
            
        }
        return sum%mod;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        Solution ob;
        cout << ob.fibSum(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends