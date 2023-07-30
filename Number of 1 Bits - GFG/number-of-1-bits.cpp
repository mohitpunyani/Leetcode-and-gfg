//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int setBits(int N) 
    {
        // Write Your Code here
        
        // 2 ki power ke last bit hamesha zero hoti hai
        
        if(N==pow(2,N)){
            return 1;
        }
        int count=0;
        while(N>0){
            if(N%2!=0){
                count++;
            }
            N=N/2;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}

// } Driver Code Ends