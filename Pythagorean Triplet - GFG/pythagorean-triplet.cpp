//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n)
	{
	    // code here
	    
	   // unordered_set<int>st;
	   // for(int i=0;i<n;i++)
	   // {
	   //     int value=arr[i]*arr[i];
	   //     st.insert(value);
	   // }
	   // sort(arr,arr+n);
	   // for(int i=0;i<n-1;i++){
	   //     for(int j=i+1;j<n;j++){
	   //         int value=arr[i]*arr[i]+arr[j]*arr[j];
	   //         if(st.find(value)!=st.end())
	   //         {
	   //             return true;
	   //         }
	   //     }
	   // }
	   // return false;
	    
	    // more optimization s.c -> o(1)
	    
	    sort(arr,arr+n);
	    for(int i=0;i<n;i++){
	        arr[i]=arr[i]*arr[i];
	    }
	    for(int i=n-1;i>=2;i--)
	    {
	        int low=0;
	        int high=i-1;
	        while(low<high){
	            if(arr[low]+arr[high]==arr[i]){
	                return true;
	            }
	            else if(arr[low]+arr[high]>arr[i])
	            {
	               
	                high--;
	            }
	            else if(arr[low]+arr[high]<arr[i])
	            {
	               low++; 
	            }
	        }
	    }
	    return false;
	    
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.checkTriplet(arr, n);
        if (ans) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}

// } Driver Code Ends