//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
	
	// METHOD 1 -> normal approach 
	 
	 vector<int>v;
	 
// 	 bool isPrime(int N)
//      {
// 	    for(int i=2;i<N;i++)
// 	    {
// 	        if(N%i==0)
// 	        {
// 	            return false;
// 	        }
// 	    }
// 	    return true;
// 	}

//   METHOD 2 (NOTE -> A NUMBER CAN BE WRITTEN AS MULTIPLICATIONS OF POWER OF PRIME FACTORS)
	
// 	bool isprime_2(int N){
	   
//         for(int i=2;i<=N;i++)
//         {
//             if(N%i==0)
//             {
//                 v.push_back(i);
//                 while(N%i==0)
//                 N=N/i;
//             }
//         }
       
// 	}
	
	// METHOD 3 -> MORE EFFECTIVE SOLUTIONS
	
		bool isprime_3(int N){
	    
	   
        for(int i=2;i<=sqrt(N);i++)
        {
            if(N%i==0)
            {
                v.push_back(i);
                while(N%i==0)
                N=N/i;
            }
        }
        if(N>1){
            v.push_back(N);
        }
       
	}
// 	vector<int>ans;
	
// 	void seive(int N)
// 	{
// 	    vector<bool>prime(N+1,true);
	    
// 	    for(int i=2;i<=N;i++)
// 	    {
// 	        if(prime[i]==true)
// 	        {
// 	            for(int j=i*i;j<=N;j=j+i)
// 	            {
// 	                prime[j]=false;
// 	            }
	            
// 	        }
	        
// 	    }
	    
// 	    for(int i=2;i<=N;i++){
// 	        if(prime[i]==true){
// 	            ans.push_back(i);
// 	        }
// 	    }
	    
	    
// 	}


    
	vector<int>AllPrimeFactors(int N)
	{
	    // Code here
	    
	   // method 1 ->
	   
	   
	   // vector<int>ans;
	   // for(int i=2;i<=N;i++)
	   // {
	   //     if(N%i==0 && isPrime(i)){
	   //         ans.push_back(i);
	   //     }
	   // }
	   // return ans;
	    
	    
	    // method 2 ->
	    
	   // isprime_2(N);
	   // return v;
	   
	   
	   // METHOD 3 ->
	   
	   // if(N==2 or N==3)
	   // {
	   //     v.push_back(N);
	   //     return v;
	        
	   // }
	   isprime_3(N);
	   return v;
	   
	     // seive(N);
	   // return ans;
	    
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