//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value


// IT'S A GOOD QUESTION AND EASY QUESTION 


class Solution{
  public:
    int threeSumClosest(vector<int> arr, int target)
    {
        // Your code goes here
        
        int n=arr.size();
        
        int ans=-1;
        
        int diff=INT_MAX;
        
        sort(arr.begin(),arr.end());
        
        // NOTE -> AGAR SUM SABSE CLOSEST AAYEGA TOH DIFFERENCE MINIMUM HOGA
        
        for(int i=0;i<n-2;i++)
        {
            int low=i+1;
            int high=n-1;
            
            while(low<high)
            {
                int sum=arr[low]+arr[high]+arr[i];
                if(sum==target)
                {
                    return target;
                }
                else if(abs(sum-target)<diff)
                {
                    diff=abs(sum-target);
                    ans=sum;

                }
                else if(abs(sum-target)==diff)
                {
                    ans=max(ans,sum);
                }
                
                if(sum>target){
                    high--;
                }
                else{
                    low++;
                }
            }
        }
        
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while(t--) {
        
        int n,target;
        cin >> n >> target;
        
        vector<int> vec(n);
        
        for(int i = 0 ; i < n ; ++ i ) 
            cin >> vec[i];
        Solution obj;
        cout << obj.threeSumClosest(vec, target) << "\n";
    }
}

//Position this line where user code will be pasted.

// } Driver Code Ends