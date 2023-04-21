//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
  
          deque<int> dq;
        vector<int> ans;
        int i=0;
        int j=0;
        // int mx=INT_MIN;
        while(j<n)
        {
            // step 1
            while(!dq.empty() && arr[j]>dq.back())
            {
                dq.pop_back();
            }
            dq.push_back(arr[j]);
            if(j-i+1==k)
            {
                // step 2
                ans.push_back(dq.front());
                // remove calculation for i
                // step -3 
                if(dq.front()==arr[i])
                {
                    dq.pop_front();
                }
                
                // this step 3 is used to solve cases like 7 6 5 4 3
                // slide the window
                i++;
                j++;
            }
            else if(j-i+1<k)
            {
                j++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends