//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int A[], int n) {
        // code here
        int N=n;
          int left[N];
        
    
        int mx=INT_MAX;
        
        int right[N];
        
        int mn=INT_MIN;
        
        for(int i=0;i<N;i++)
        {
            mx=min(A[i],mx);
            left[i]=mx;
        }
        
        for(int i=N-1;i>=0;i--)
        {
            mn=max(A[i],mn);
            right[i]=mn;
        }
        
           int ans=0,i=0,j=0;
        
        while(i<N and j<N) {
            if(left[i]<=right[j]) {
                ans=max(ans,j-i);
                j++;
            }
            else {
                i++;
            }
        }
        return ans;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends