//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
vector<int> ans;
void solve(vector<int>&arr,int N, int index,int sum){
    if(index>=N){
        ans.push_back(sum);
        return ;
    }
    int temp=sum+arr[index];
    solve(arr,N,index+1,temp);
    temp=temp-arr[index];
    solve(arr,N,index+1,temp);
}
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        
        int sum=0;
        solve(arr,N,0,sum);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends