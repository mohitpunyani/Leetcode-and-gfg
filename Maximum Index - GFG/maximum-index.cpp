//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    
    // BE A GOOD OBSERVER
    
    int maxIndexDiff(int A[], int N) 
    { 
        // Your code here
        
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
        
        while(j<N) {
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
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends