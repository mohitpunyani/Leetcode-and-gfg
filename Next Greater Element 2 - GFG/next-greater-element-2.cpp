//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> nextGreaterElement(int N, vector<int>& arr)
    {
        // code here
        
        vector<int>ans(N,-1);
        
        stack<pair<int,int>>st;
        
        st.push({arr[0],0});
        
        for(int i=1;i<2*N;i++)
        {
            int index=i%N;
            while(!st.empty() &&  st.top().first<arr[index])
            {
                ans[st.top().second]=arr[index];
                st.pop();
            }
            
            if(i<N){
                st.push({arr[i],i});
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
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        vector<int> ans = obj.nextGreaterElement(N, arr);
        for (auto &it : ans) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends