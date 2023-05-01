//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int first(int arr[],int n,int x){
    int low=0;
    int high=n-1;
    int ans=-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        
        if(arr[mid]>x){
            high=mid-1;
        }
        else if(arr[mid]<x){
            low=mid+1;
        }
        else{
            // equal to case
            
            // mid==0 denotes that we reach at first index so we can't compare mid-1 with mid that's
            // why i use or mid==0
            if((arr[mid-1]!=arr[mid] && mid>0) or mid==0){
                ans=mid;
                return ans;
            }
            else {
                high=mid-1;
            }
        }
        
    }
    return ans;
}
int last(int arr[],int n,int x){
    int low=0;
    int high=n-1;
    int ans=-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        
        if(arr[mid]>x){
            high=mid-1;
        }
        else if(arr[mid]<x){
            low=mid+1;
        }
        else{
            // equal to case
            
            // mid== n-1 denotes that we reach at the end of the array, now we can't go further 
            // and we can't compare mid+1 with mid so we use mid==n-1 
            
            if(arr[mid+1]!=arr[mid]  or mid==n-1){
                ans=mid;
                return ans;
            }
            else {
                low=mid+1;
            }
        }
        
    }
    return ans;
}
vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int>ans={-1,-1};
    int ans1=first(arr,n,x);
    if(ans1==-1){
        return ans;
    }
    int ans2=last(arr,n,x);
    if(ans2==-1){
        return ans;
    }
    ans[0]=ans1;
    ans[1]=ans2;
    return ans;
    
    
    
    
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends