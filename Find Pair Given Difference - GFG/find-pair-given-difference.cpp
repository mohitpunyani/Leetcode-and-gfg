//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends


bool findPair(int arr[], int size, int n)
{
    //code
    
    // int low=0;
    // int high=size-1; // isese code fatega 
    
    // sort(arr,arr+size);
    // while(low<high)
    // {
    //     int diff=arr[high]-arr[low];
        
    //     if(diff==n){
    //         return true;
    //     }
    //     else if(diff>n){
    //         high--;
    //     }
    //     else{
    //         low++;
    //     }
    // }
    // return -1;
    
  
    sort(arr,arr+size);
    
    // imp approach
    int i = 0;  
    int j = 1;
 
    while (j<size)
    {
        int diff=arr[j]-arr[i];
        if (diff== n && i!=j)
        {
            return true;
        }
        else if (diff < n)
            j++;
        else
            i++;
    }
 
    return false;

}