//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int setBits(int N) 
    {
        // Write Your Code here
        
        // 2 ki se divisible ki last bit hamesha zero hoti hai
        
        
        // int count=0;
        // while(N>0){
        //     if(N%2!=0){
        //         count++;
        //     }
        //     N=N/2;
        // }
        // return count;
        
        
        // another way
        
        int res=0;
        while(N>0)
        {
            // check last bit is set or not
            if(N&1!=0){
                res++;
            }
            N=N>>1;
        }
        return res;
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