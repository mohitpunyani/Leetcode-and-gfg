//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:
	bool recreationalSpot(int arr[], int n){
		// Your code goes here 
		
		 int second=-1;
        
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            if(second>arr[i]){
                return true;
            }
            while(!st.empty() && arr[i]>st.top())
            {
            
                second=st.top();
                st.pop();
            }
            st.push(arr[i]);
            
            
        }
        return false;
	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution ob;
		if(ob.recreationalSpot(arr, n))
		    cout<<"True"<<endl;
		else
		    cout<<"False"<<endl;
	}
	return 0;
}
// } Driver Code Ends