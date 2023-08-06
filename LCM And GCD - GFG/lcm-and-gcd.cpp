//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    // long long lcm(long long A,long long B)
    // {
          
       
        
    //     long long ans=max(A,B);
        
    //     while(true)
    //     {
    //         if(ans%A==0 && ans%B==0)
    //         {
    //             return ans;
    //         }
    //         ans++;
            
    //     }
    //     return ans;

       
    // }
    
    long long hcf(long long A,long long B)
    {
        if(B==0){
            return A;
        }
        else{
            return hcf(B,A%B);
        }
    }
    vector<long long> lcmAndGcd(long long A , long long B) 
    {
        // code here
        
        
        vector<long long >ans;
        long long hc=hcf(A,B);
        // long long lc=lcm(A,B);
        
        long long lc=(A*B)/hc;
         ans.push_back(lc);
         ans.push_back(hc);
      return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends