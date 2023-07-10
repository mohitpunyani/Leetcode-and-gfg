//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      
    //   sort(arr,arr+N);
      
    //   int ans=1;
      
    //   int res=INT_MIN;
      
    //   if(N==1){
    //       return 1;
    //   }
    //   for(int i=1;i<N;i++)
    //   {
    //       if(arr[i]-arr[i-1]==1)
    //       {
    //           ans++;
    //       }
    //       if(arr[i]-arr[i-1]>1)
    //       {
    //           ans=1;
    //       }
    //       if(arr[i]-arr[i-1]==0)
    //       {
    //           continue;
    //       }
    //       res=max(ans,res);
      
          
    //   }
    //   return res;
      
      // USING SET DATA STRUCTURE (REDUCE TIME COMPLEXITY)
      
       
       set<int> ss;
        for (int i=0; i < N; i++)
            ss.insert(arr[i]);

        int ans = INT_MIN, curr = 0;
    
        for (auto i : ss)
        {
            if (ss.find(i - 1)!=ss.end())
            {
                curr++;
            }
    
            else if(ss.find(i-1)==ss.end())
                curr = 1;
    
            ans = max(curr, ans);
        }
            
        return ans;
    } 
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends