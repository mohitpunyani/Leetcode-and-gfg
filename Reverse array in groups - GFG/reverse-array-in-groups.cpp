//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution{
public:

void reversearray(vector<long long> &arr,int low,int high,int size)
{
    // pahle complete array ko reverse kiya aur phir rotate kiya n-k se
    
        while(low<high)
        {
            swap(arr[low],arr[high]);
            low++;
            high--;
        }
        return ;
    
}
    //Function to reverse every sub-array group of size k.
    void reverseInGroups(vector<long long>& arr, int n, int k){
        // code here
        
        //  algo
        
        // this is my way to think and i write the code.
        if(k>=n){
            reversearray(arr,0,n-1,n);
        }
        else
        {
            int low=0;
            int high=k-1;
            while(low<high)
            {
                reversearray(arr,low,high,n);
                low=low+k;
                high=min(low+k-1,n-1);
                
                
                
            }
        }
        
        // it's not my way to write the code
        
        // for(int i=0;i<n;i=i+k)
        // {
        //     int  left=i;
        //     int high=min(i+k-1,n-1);
        //     reversearray(arr,left,high,n);
            
        // }
        
        
        
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