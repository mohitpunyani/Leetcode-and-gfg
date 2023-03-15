//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) 
    {
        // code here
        
        // sort(arr,arr+n);
        // int j=0;
        // int i=1;
        // vector<int> ans;
        // while(i<n && j<n){
        //     if(arr[i]!=arr[j]){
        //         j=i;
        //     }
        //     else{
        //         ans.push_back(arr[j]);
        //     }
        //     i++;
        // }
        // ans.erase( unique( ans.begin(), ans.end() ), ans.end() );
        // if(ans.size()==0){
        //     ans.push_back(-1);
        //     return ans;
        // }
        // return ans;
        
        // second solution using map
        
        vector<int> ans;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        for(auto &y:mp){
            if(y.second>1){
                ans.push_back(y.first);
            }
        }
        sort(ans.begin(),ans.end());
        if(ans.size()==0){
            ans.push_back(-1);
            return ans;
        }
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends