//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
    public:
    
    // NOTE -> IT'S A GOOD QUESTION
    //Function to find most frequent word in an array of strings.
    string mostFrequentWord(string arr[], int n) 
    {
        // code here
        unordered_map<string,int>mp;
        
        int maxi=0;
        
        string max_ans="";

        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
            maxi=max(maxi,mp[arr[i]]);
        }
        for(int i=0;i<n;i++){
            if(maxi==mp[arr[i]]){
                mp[arr[i]]--;
                max_ans=arr[i];
            }
        }
        return max_ans;
    
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.mostFrequentWord(arr, n) << endl;
    }
    return 0;
}

// } Driver Code Ends