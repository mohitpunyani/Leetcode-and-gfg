//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
vector<string>res;
    void solve(int ind,string S,int n,string ans){
        if(ind==n){
            res.push_back(ans);
            return;
        }
        solve(ind+1,S,n,ans+' '+S[ind]);
        solve(ind+1,S,n,ans+S[ind]);
        return ;
    }

    vector<string> permutation(string S)
    {
        // Code Here
        
        // jaise dry run kar raha vaise code likhade
      
        
         int n=S.size();
        string ans="";
        ans+=S[0];
        solve(1,S,n,ans);
        return res;
    }
};

//{ Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}

// } Driver Code Ends