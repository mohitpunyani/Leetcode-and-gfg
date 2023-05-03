//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    int findMidSum(int ar1[], int ar2[], int n)
    {
            // code here 
            
            // 1. approach -> using o(nlogn)
            
            // int i=0;
            // int j=0;
            // int k=n-1;
            // while(i<=k && j<n)
            // {
            //     if(ar1[i]>ar2[j])
            //     {
            //         swap(ar1[k],ar2[j]);
            //         j++;
            //         k--;
                    
            //     }
            //     else{
            //         i++;
            //         continue;
            //     }
                
            // }
            // sort(ar1,ar1+n);
            // sort(ar2,ar2+n);
            
            // int sum=ar1[n-1]+ar2[0];
            // return sum;
            
            // 2. approach -> using binary search o(logn)
            
            // you can use binary search on any array because both of them are same side
            
            // VERY IMPORTANT QUESTION 
            
            int low=0;
            int high=n;
            
            int total = n+n;
            // when length are different then apply binary search on shortest array to avoid index out of board
            
            while(low<=high)
            {
                // initialize the cut or partitions
                
                
                int cut1=low+(high-low)/2;
                
                // total required - already present
                
                int cut2=n-cut1;
                
                // initialize l1,l2,r1,r2
                int l1=cut1==0?INT_MIN:ar1[cut1-1];
                int l2=cut2==0?INT_MIN:ar2[cut2-1];
                int r1=cut1==n?INT_MAX:ar1[cut1];
                int r2=cut2==n?INT_MAX:ar2[cut2];
                
                // we get always even length 
                if(l1<=r2 and l2<=r1)
                {
                    return max(l1,l2)+min(r1,r2);
                    
                }
                else if(l1>r2)
                {
                    high=cut1-1;
                    
                }
                else if(l2>r1)
                {
                    low=cut1+1;
                    
                }
                
            }
            return 0;
            
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int ar1[n], ar2[n];
        for (i = 0; i < n; i++) {
            cin >> ar1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> ar2[i];
        }
        Solution ob;
        auto ans = ob.findMidSum(ar1, ar2, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends