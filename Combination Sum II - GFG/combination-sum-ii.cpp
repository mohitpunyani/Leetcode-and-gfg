//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:

void solve(int index,int k,vector<int>&arr,vector<int>&temp,vector<vector<int>>&ans)
{
    // if(k<0){
    //     return ;
        
    // }
    if(k==0){
        ans.push_back(temp);
        return ;
    }
    for(int i=index;i<arr.size();i++)
    {
        if(i>index && arr[i]==arr[i-1]) 
        continue;

        if(arr[i]>k)
        {
            break;
            // iska matlab hai ki aage wali values ke liye bhi solution nahi hai 
        }
        else{
        temp.push_back(arr[i]);
        solve(i+1,k-arr[i],arr,temp,ans);
        temp.pop_back();
    }
    }
    return ;
    
}

    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        //  code here
        
        // code here 
        vector<vector<int>>ans;
        vector<int>temp;
        sort(arr.begin(),arr.end());
        solve(0,k,arr,temp,ans);
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
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends