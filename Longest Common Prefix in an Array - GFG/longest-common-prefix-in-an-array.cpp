//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     
     
     // LOVE BABBAR
     
     // A GOOD QUESTION 
     
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        
        // algo 
        
        // step 1 -> take first string 
        
        // step 2 -> compare all the characters of first string with the remaining string
        
        string ans="";
        
        bool match=true;
        // traverse first string
        
        
        for(int i=0;i<arr[0].size();i++)
        {
            char ch=arr[0][i];
            
            // traverse remaining string
            
            match=true;

            for(int j=1;j<N;j++)
            {
                // not match 
                if(arr[j][i]!=ch || arr[j].size()<i)
                {
                    match=false;
                    break;
                }
                else{
                    continue;
                }
                
            }
            if(match==false)
            {
                continue;
            }
            else{
                ans.push_back(ch);
            }
            
        }
        if(ans.size()==0){
            return "-1";
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends