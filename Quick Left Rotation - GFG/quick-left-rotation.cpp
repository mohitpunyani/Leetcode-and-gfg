//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	void reverse(int arr[],int low,int high)
	{
	    while(low<high){
	        swap(arr[low],arr[high]);
	        low++;
	        high--;
	    }
	}
	public:
	
	void leftRotate(int arr[], int k, int n) 
	{ 
	   // Your code goes here
	   k=k%n;
	   reverse(arr,0,k-1);
	   reverse(arr,k,n-1);
	   reverse(arr,0,n-1);
	} 
		 

};

//{ Driver Code Starts.

int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
	    cin >> n;
	    int k;
	    cin >> k;
	    int a[n];
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	        // um[a[i]]++;
	    }


       

        Solution ob;
        ob.leftRotate(a,k,n);
        
        for (int i = 0; i < n; i++) 
        	cout << a[i] << " "; 

	    cout << "\n";
	     
    }
    return 0;
}



// } Driver Code Ends