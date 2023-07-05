//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // SUBARRAY -> PRIORITY IS CONITNUOUS
        
        // JO MAP KA SIZE HOGA WAHI TOH UNIQUE CHARACTERS HONGE
        
        // Your code goes here   
        
        // variable size sliding window question 
        
        // just do observation very carefully
        
        
        unordered_map<int,int>mp;
        
        for(int i=0;i<str.size();i++)
        {
            mp[str[i]]++;
            
        }
        
        
        int ans=INT_MAX;
        
        int k=mp.size();
        
        mp.clear();
        
        int i=0;
        int j=0;
        while(j<str.size())
        {
            mp[str[j]]++;
            if(mp.size()<k)
            {
                j++;
            }
            else if(mp.size()==k)
            {
                while(mp.size()==k)
                {
                    ans=min(ans,j-i+1);
                    mp[str[i]]--;
                    if(mp[str[i]]==0)
                    {
                        mp.erase(str[i]);
                    }
                    i++;
                }
                j++;
            }
        
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends