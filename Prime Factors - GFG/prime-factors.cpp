//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
	
	vector<int>ans;
     
     
     // using seive algorithm
     
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
          ans.push_back(i);
          while(N%i == 0)
          {
            //   ans.push_back(i);
              N = N/i;
          }
       }
	    
    }
}
	vector<int>AllPrimeFactors(int N)
	{
	    // Code here
	    
	    
	    prime_factor(N);
	    return ans;
	    
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.AllPrimeFactors(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	}  
	return 0;
}
// } Driver Code Ends