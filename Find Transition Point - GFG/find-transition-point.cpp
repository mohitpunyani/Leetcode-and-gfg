//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << transitionPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends

int first(int arr[],int n,int x,int &ans){
    int low=0;
    int high=n-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        
        if(arr[mid]<x){
            low=mid+1;
        }
        else if(arr[mid]==x)
        {
            // equal to case
            
            // mid==0 denotes that we reach at first index so we can't compare mid-1 with mid that's
            
            // why i use or mid==0
            
            if((arr[mid-1]!=arr[mid] && mid>0) or mid==0){
                ans=mid;
                return ans;
            }
            else {
                high=mid-1;
            }
        }
        
    }
    return ans;
}
int transitionPoint(int arr[], int n) 
{
    // code here
    
    // 1 is the key
    int ans=-1;
    return first(arr,n,1,ans);
    
}