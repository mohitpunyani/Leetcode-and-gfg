//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
      
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
                
                // this step 3 is used to solve cases like 7 6 5 4 3 // i got it
                
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

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends