//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int mindGame(int K) {
        // code here
        
        // BACHO WALI GAME HAI
        
    //   int temp=K;
    //   K=K*2;// code here
    //   K=K+temp;
    //   K=K/2;
    //   K=K-temp;
    //   return K;
     
     
     return K/2;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int K;
        
        cin>>K;

        Solution ob;
        cout << ob.mindGame(K) << endl;
    }
    return 0;
}
// } Driver Code Ends