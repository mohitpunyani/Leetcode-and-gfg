//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
  public:
    vector<int> arranged(int a[],int n)
    {
        // thoda sa hint liya
        vector<int> ans(n);
        int i=0;
        int j=0;
        for(int j=0;j<n;j++){
            if(a[j]>0)
            {
                ans[i]=a[j];
                i=i+2;
            }
            else {
                continue;
            }
        }
        int k=1;
        for(int j=0;j<n;j++){
            if(a[j]<0){
                ans[k]=a[j];
                k=k+2;
            }
            else{
                continue;
            }
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
    int n,i,j;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    vector<int> ans;
    Solution obj;
    ans=obj.arranged(a,n);
    for(i=0;i<n;i++)
        cout<<ans[i]<<" ";
    cout<<"\n";
    }
}

// } Driver Code Ends