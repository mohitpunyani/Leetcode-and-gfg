//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        // Your code here
        
        vector<long long int>ans(n,-1);
        
        // stack of value and index.
        
        stack<pair<long long int,long long int>>st;
        
        st.push({arr[0],0});
        
        for(int i=0;i<arr.size();i++)
        {
           while(!st.empty() && st.top().first<arr[i])
           {
            ans[st.top().second]=arr[i];
            st.pop();
           }
        st.push({arr[i],i});
        }
        
        return ans;
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
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends