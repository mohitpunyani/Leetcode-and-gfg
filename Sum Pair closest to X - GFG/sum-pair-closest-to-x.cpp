//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

// NOTE -> SIMILAR TO THREE SUM CLOSEST
    vector<int> sumClosest(vector<int>arr, int x)
    {
        // code here
        
        vector<int>ans;
        
        int n=arr.size();
        
        int low=0;
        
        int high=n-1;
        
        int diff=INT_MAX;
        
        // take two variables
        
        
        int first;
        
        int second;
        
       
        while(low<high)
        {
            int sum=arr[low]+arr[high];
            
            if(sum==x)
            {
                first=arr[low];
                
                second=arr[high];
                
                break;
            }
            else if(abs(sum-x)<diff)
            {
                diff=abs(sum-x);
                first=arr[low];
                second=arr[high];
            }
            
            else if(abs(sum-x)==diff)
            {
                if(sum>first+second)
                {
                    first=arr[low];
                    second=arr[high];
                }
                
            }
            if(sum>x)
            {
                high--;
            }
            else{
                low++;
            }
            
        }
        ans.push_back(first);
        ans.push_back(second);
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumClosest(arr, x);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends