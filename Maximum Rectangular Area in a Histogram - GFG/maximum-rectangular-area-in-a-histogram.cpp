//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    private:
    
    vector<int> nextsmallerelements(long long arr[], int  n)
    {
        stack<pair<long long ,int >>s;
        
        s.push({arr[0],0});
        
        vector<int> ans(n,-1);

        for(int i = 1; i<n; i++){
        
            while(!s.empty()  && s.top().first> arr[i])
            {
                ans[s.top().second]=i;
                s.pop();
            }
            s.push({arr[i],i});
        }
        return ans;
    }

    vector<int> prevsmallerelements(long long arr[], int n)
    {
        
      
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i= 0; i < n; i++){
            int  curr = arr[i];

            while(s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        
        vector<int > next(n); 
        next = nextsmallerelements(arr, n);
        
        vector<int> prev(n); 
        prev = prevsmallerelements(arr, n);
        
        long long area = INT_MIN;
        
        for(int i = 0; i < n ; i++){
            
            long long l = arr[i];
            
            if(next[i] == -1){
                next[i] = n;
            }
            
            long long b = next[i] - prev[i] - 1;
            
            long long newarea = l * b;
            
            area = max(newarea, area);
        }
        
        return area;
    
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends