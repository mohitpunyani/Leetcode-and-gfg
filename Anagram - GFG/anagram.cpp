//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        // Your code here
        
        
        // unordered_map<char,int>mp;
        // for(auto x:a){
        //     mp[x]++;
        // }
        // for(auto y:b)
        // {
        //     mp[y]--;
        //     if(mp[y]==0)
        //     {
        //         mp.erase(y);
        //     }
        // }
        // if(mp.size()!=0){
        //     return false;
        // }
        // return true;
        
        
        // constant space
        
        int sum1=0;
        int sum2=0;
        long long pr1=1;
        long long pr2=1;
        
        for(int i=0;i<a.size();i++){
            sum1=sum1+(int)a[i];
            pr1=pr1*a[i];
        }
        for(int i=0;i<b.size();i++){
            sum2=sum2+(int)b[i];
            pr2=pr2*b[i];
        }
        return (sum1==sum2 && pr1==pr2);
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends