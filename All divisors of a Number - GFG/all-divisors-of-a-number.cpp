//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void print_divisors(int n)
    {
        // Code here.
        
        // method 1 -> naive approach 
        
        
        // for(int i=1;i<=n;i++)
        // {
        //     if(n%i==0)
        //     {
        //         cout<<i<<" ";
        //     }
        // }
        
        
        // method 2 -> THIS WILL PRINT ALL THE DIVISOR BUT NOT IN ORDER
        
        // using the property that divisor always exist in pair
        // ek divisor i toh dusara n/i hoga
        
        // for(int i=1;i<=sqrt(n);i++)
        // {
        //     if(n%i==0)
        //     {
        //         cout<<i<<" ";
        //         if(i*i!=n)
        //         {
        //             cout<<(n/i)<<" ";
        //         }
        //     }
            
        // }
        
        
        // method 3 -> more optimization 
        
        int i;
        for(i=1;i<sqrt(n);i++)
        {
            if(n%i==0)
            {
                cout<<i<<" ";
            }
            
        }
          if(i>sqrt(n))  // if i > sqrt(n)
           i--;
        for(i;i*i<=n&&i>=1;i--)
        {
            if(n%i==0)
                cout<<n/i<<" ";
        }
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Solution ob;
        ob.print_divisors(n);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends