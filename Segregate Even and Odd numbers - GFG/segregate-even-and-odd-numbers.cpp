//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

	void segregateEvenOdd(int arr[], int n) 
	{
	    // code here
	    int i=0;
	    int j=0;
	    for(int j=0;j<n;j++){
	        if(arr[j]%2==0){
	            // even
	            swap(arr[i],arr[j]);
	            i++;
	        }
	        else if(arr[j]%2!=0){
	            continue;
	            
	        }
	    }
	    sort(arr,arr+i);
	    sort(arr+i,arr+n);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.segregateEvenOdd(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends