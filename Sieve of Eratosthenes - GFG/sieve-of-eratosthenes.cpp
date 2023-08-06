//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:

// seive algorithm

   vector<int>ans;
   
   void seive(int N)
   {
       vector<bool>prime(N+1,true);
       
       for(int i=2;i<=sqrt(N);i++)
       {
           if(prime[i])
           {
                for(int j=i*i;j<=N;j+=i)
               {
                   prime[j]=false;
               }
           }
       }
       
       for(int i=2;i<=N;i++){
           if(prime[i]){
               ans.push_back(i);
           }
       }
       
    
   }
    vector<int> sieveOfEratosthenes(int N)
    {
        // Write Your Code here
        
        seive(N);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends