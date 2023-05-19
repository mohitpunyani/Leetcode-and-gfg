//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution{
    public:
    void reverse(vector<long long>&arr,int low,int high){
        while(low<high){
            swap(arr[low],arr[high]);
            low++;
            high--;
        }
    }
    void reverseInGroups(vector<long long>&arr,int n,int k)
    {
        for(int i=0;i<n;i=i+k)
        {
            int low=i;
            int high=min(i+k-1,n-1);
            reverse(arr,low,high);
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t; 
    cin >> t; 
    while(t--){ 
        int n;
        cin >> n; 
        vector<long long> arr; 
        int k;
        cin >> k; 

        for(long long i = 0; i<n; i++)
        {
            long long x;
            cin >> x; 
            arr.push_back(x); 
        }
        Solution ob;
        ob.reverseInGroups(arr, n, k);
        
        for(long long i = 0; i<n; i++){
            cout << arr[i] << " "; 
        }
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends