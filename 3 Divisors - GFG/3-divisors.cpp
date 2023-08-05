//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:


    // using seive algorithm
    
    
    
    
    long long isprime(long long n)
    {
        

        vector<bool> prime(sqrt(n)+1,true);

        long long cnt=0;

        for(int i=2;i<=sqrt(n);i++){

            if(prime[i]==true)
            {

                for(int j=i*i;j<=sqrt(n);j=j+i){

                    prime[j]=false;

                }

            }

        }

        for(int i=2;i<=sqrt(n);i++){

            if(prime[i])
                cnt++;

        }

        return cnt;

    }
    vector<int> threeDivisors(vector<long long> query, int q)
    {
        // Write your code here
        
        // catch -> all perfect squares that have a prime numbers as square 
        // root are output numbers
        
       // here we will using SEIVE ALGORITHM
      
       
       
         vector<int>ans;

        for(int i=0;i<q;i++){

            long long val = query[i];
            
            long long cnt = isprime(val);

            ans.push_back(cnt);

        }

        return ans;
       
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while(t--){
        int q;cin>>q;
        vector<long long> query(q);
        for(int i=0;i<q;i++){
            cin>>query[i];
        }
        Solution ob;
            
        vector<int> ans = ob.threeDivisors(query,q);
        for(auto cnt : ans) {
            cout<< cnt << endl;
        }
    }
    return 0;
}
// } Driver Code Ends