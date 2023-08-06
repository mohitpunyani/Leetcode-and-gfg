//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  
  // unique prime factors using seive algorithm
  
  vector<int>ans;
   
    void sieve() {}
    
        void prime_factor(int N)
        {
            
        vector<bool>prime(N+1,true);
	    
	    for(long long i=2;i<=sqrt(N);i++)
	    {
	        if(prime[i]==true)
	        {
	            for(long long j=(long long) i*i;j<=sqrt(N);j+=i)
	            {
	                prime[j]=false;
	            }
	            
	        }
	        
	    }
	    
	
    for(long long int i = 2; i<=N; i++)
   {
       if(prime[i] && N%i == 0)
       {
           while(N%i == 0)
           {
               ans.push_back(i);
               N = N/i;
           }
       }
	    
    }
}

    vector<int> findPrimeFactors(int N) {

        // Write your code here
        
        prime_factor(N);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n;
        cin >> n;

        Solution obj;
        obj.sieve();
        vector<int> vec = obj.findPrimeFactors(n);
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends